
#include "snapshot_history_encoder.h"
#include "utils.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/object.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

Ref<_SnapshotHistoryEncoder> _SnapshotHistoryEncoder::new_(Ref<_PropertyHistoryBuffer> p_history, Ref<PropertyCache> p_property_cache, Ref<_NetworkSchema> p_schema) {
	Ref<_SnapshotHistoryEncoder> ref;
	ref.instantiate();
	ref->_history = p_history;
	ref->_property_cache = p_property_cache;
	ref->_schema = p_schema;
	return ref;
}

void _SnapshotHistoryEncoder::set_properties(Array properties) {
	if (_properties != properties) {
		_version = (_version + 1) % 256;
		_properties = properties.duplicate();
	}
}

PackedByteArray _SnapshotHistoryEncoder::encode(int tick, TypedArray<PropertyEntry> properties) {
	Ref<_PropertySnapshot> snapshot = _history->get_snapshot(tick);

	Ref<StreamPeerBuffer> buffer;
	buffer.instantiate();
	buffer->put_u8(_version);

	for (int i = 0; i < properties.size(); i++) {
		Ref<PropertyEntry> property_entry = properties[i];
		String path = property_entry->_to_string();
		_schema->encode(path, snapshot->get_value(path), buffer);
	}
	//UtilityFunctions::print(buffer->get_data_array());
	return buffer->get_data_array();
}

Ref<_PropertySnapshot> _SnapshotHistoryEncoder::decode(PackedByteArray data, TypedArray<PropertyEntry> properties) {
	Ref<_PropertySnapshot> result = _PropertySnapshot::new_();

	Ref<StreamPeerBuffer> buffer;
	buffer.instantiate();
	buffer->set_data_array(data);
	uint8_t packet_version = buffer->get_u8();

	if (packet_version != _version) {
		if (!_has_received) {
			// First packet, assume version is OK
			_version = packet_version;
		} else {
			// Version mismatch, can't parse
			_logger->warning(vformat("Version mismatch! own: %d, received: %s", _version, packet_version));
			return result;
		}
	}

	for (int i = 0; i < properties.size(); i++) {
		if (buffer->get_available_bytes() == 0) {
			_logger->warning(vformat("Received snapshot with %d entries, with %d known - parsing as much as possible", result->size(), properties.size()));
			break;
		}
		Ref<PropertyEntry> property = properties[i];
		String path = property->to_string();
		Variant value = _schema->decode(path, buffer);
		result->set_value(path, value);
	}
	_has_received = true;
	return result;
}

bool _SnapshotHistoryEncoder::apply(int tick, Ref<_PropertySnapshot> snapshot, int sender) {
	auto network_rollback = Utils::get_autoload("NetworkRollback");
	if (tick < (int)network_rollback->get("history_start")) {
		// State too old!
		_logger->error(vformat("Received full snapshot for %s, rejecting because older than %s frames", tick, network_rollback->get("history_limit")));
		return false;
	}

	if (sender > 0) {
		snapshot->sanitize(sender, _property_cache);
		if (snapshot->is_empty()) {
			return false;
		}
	}

	_history->set_snapshot(tick, snapshot);
	return true;
}

Ref<_NetfoxLogger> _SnapshotHistoryEncoder::_logger;

void _SnapshotHistoryEncoder::_bind_methods() {
	_logger = _NetfoxLogger::for_netfox("_SnapshotHistoryEncoder");

	ClassDB::bind_static_method("_SnapshotHistoryEncoder", D_METHOD("new_", "p_history", "p_property_cache"), &_SnapshotHistoryEncoder::new_);
	ClassDB::bind_method(D_METHOD("set_properties", "properties"), &_SnapshotHistoryEncoder::set_properties);
	ClassDB::bind_method(D_METHOD("encode", "tick", "properties"), &_SnapshotHistoryEncoder::encode);
	ClassDB::bind_method(D_METHOD("decode", "data", "properties"), &_SnapshotHistoryEncoder::decode);
	ClassDB::bind_method(D_METHOD("apply", "tick", "snapshot", "sender"), &_SnapshotHistoryEncoder::apply, DEFVAL(-1));
}
