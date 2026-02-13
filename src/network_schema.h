#pragma once
#include "serializers.h"
#include <godot_cpp/classes/stream_peer_buffer.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>

using namespace godot;

class _NetworkSchema : public RefCounted {
	GDCLASS(_NetworkSchema, RefCounted);

protected:
	Dictionary _serializers;
	Ref<_VariantSerializer> _fallback;
	static void _bind_methods() {
		ClassDB::bind_static_method("_NetworkSchema", D_METHOD("new_", "p_serializers"), &_NetworkSchema::new_);
	};

public:
	_NetworkSchema() {
		_fallback.instantiate();
	};
	~_NetworkSchema() {};
	void encode(String path, Variant value, Ref<StreamPeerBuffer> &buffer) {
		Ref<NetworkSchemaSerializer> serializer = Object::cast_to<NetworkSchemaSerializer>(_serializers.get(path, _fallback));
		serializer->encode(value, buffer);
	}
	Variant decode(String path, Ref<StreamPeerBuffer> &buffer) {
		Ref<NetworkSchemaSerializer> serializer = Object::cast_to<NetworkSchemaSerializer>(_serializers.get(path, _fallback));
		return serializer->decode(buffer);
	}
	static Ref<_NetworkSchema> new_(Dictionary p_serializers) {
		Ref<_NetworkSchema> ref;
		ref.instantiate();
		ref->_serializers = p_serializers;
		return ref;
	}
};
