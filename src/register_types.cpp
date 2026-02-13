#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "bimap.h"
#include "diff_history_encoder.h"
#include "logger.h"
#include "network_schema.h"
#include "peer_visibility_filter.h"
#include "property_cache.h"
#include "property_config.h"
#include "property_entry.h"
#include "property_history_buffer.h"
#include "property_snapshot.h"
#include "redundant_history_encoder.h"
#include "ring_buffer.h"
#include "rollback_freshness_store.h"
#include "rollback_history_recorder.h"
#include "rollback_history_transmitter.h"
#include "schemas_static.hpp"
#include "serializers.h"
#include "set.h"
#include "snapshot_history_encoder.h"

using namespace godot;

void initialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		return;
	GDREGISTER_CLASS(_NetfoxLogger);
	GDREGISTER_CLASS(_SetIterator);
	GDREGISTER_CLASS(_Set);
	GDREGISTER_CLASS(_BiMapIterator);
	GDREGISTER_CLASS(_BiMap);
	GDREGISTER_CLASS(_RingBuffer);
	GDREGISTER_CLASS(PropertyEntry);
	GDREGISTER_CLASS(PropertyCache);
	GDREGISTER_CLASS(_PropertyConfig);
	GDREGISTER_CLASS(_HistoryBuffer);
	GDREGISTER_CLASS(_PropertyHistoryBuffer);
	GDREGISTER_CLASS(_PropertySnapshot);
	GDREGISTER_CLASS(PeerVisibilityFilter);
	GDREGISTER_CLASS(_DiffHistoryEncoder);
	GDREGISTER_CLASS(_RedundantHistoryEncoder);
	GDREGISTER_CLASS(_SnapshotHistoryEncoder);
	GDREGISTER_CLASS(_RollbackHistoryRecorder);
	GDREGISTER_CLASS(_RollbackHistoryTransmitter);
	GDREGISTER_CLASS(RollbackFreshnessStore);
	GDREGISTER_CLASS(_NetworkSchema);
	GDREGISTER_CLASS(NetworkSchemaSerializer);
	GDREGISTER_CLASS(_VariantSerializer);
	GDREGISTER_CLASS(_StringSerializer);
	GDREGISTER_CLASS(_BoolSerializer);
	GDREGISTER_CLASS(_Uint8Serializer);
	GDREGISTER_CLASS(_Uint16Serializer);
	GDREGISTER_CLASS(_Uint32Serializer);
	GDREGISTER_CLASS(_Uint64Serializer);
	GDREGISTER_CLASS(_Int8Serializer);
	GDREGISTER_CLASS(_Int16Serializer);
	GDREGISTER_CLASS(_Int32Serializer);
	GDREGISTER_CLASS(_Int64Serializer);
	GDREGISTER_CLASS(_Float16Serializer);
	GDREGISTER_CLASS(_Float32Serializer);
	GDREGISTER_CLASS(_Float64Serializer);
	GDREGISTER_CLASS(_GenericVec2Serializer);
	GDREGISTER_CLASS(_GenericVec3Serializer);
	GDREGISTER_CLASS(_Normal2Serializer);
	GDREGISTER_CLASS(_Normal3Serializer);
	GDREGISTER_CLASS(_GenericVec4Serializer);
	GDREGISTER_CLASS(_GenericQuaternionSerializer);
	GDREGISTER_CLASS(_GenericTransform2DSerializer);
	GDREGISTER_CLASS(_GenericTransform3DSerializer);
	GDREGISTER_CLASS(_QuantizingSerializer);
	GDREGISTER_CLASS(_ModuloSerializer);
	GDREGISTER_CLASS(_ArraySerializer);
	GDREGISTER_CLASS(_DictionarySerializer);
	GDREGISTER_CLASS(NetworkSchemas);
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE)
		return;
}

extern "C" {
// Initialization
GDExtensionBool GDE_EXPORT netfox_boost_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
	init_obj.register_initializer(initialize_gdextension_types);
	init_obj.register_terminator(uninitialize_gdextension_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
