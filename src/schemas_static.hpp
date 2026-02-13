#pragma once
//#include "serializers.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class NetworkSchemas : public RefCounted {
	GDCLASS(NetworkSchemas, RefCounted);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("variant"), &NetworkSchemas::variant);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("string"), &NetworkSchemas::string);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("bool8"), &NetworkSchemas::bool8);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("uint8"), &NetworkSchemas::uint8);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("uint16"), &NetworkSchemas::uint16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("uint32"), &NetworkSchemas::uint32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("uint64"), &NetworkSchemas::uint64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("int8"), &NetworkSchemas::int8);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("int16"), &NetworkSchemas::int16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("int32"), &NetworkSchemas::int32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("int64"), &NetworkSchemas::int64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("float16"), &NetworkSchemas::float16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("float32"), &NetworkSchemas::float32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("float64"), &NetworkSchemas::float64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("sfrac8"), &NetworkSchemas::sfrac8);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("sfrac16"), &NetworkSchemas::sfrac16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("sfrac32"), &NetworkSchemas::sfrac32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("ufrac8"), &NetworkSchemas::ufrac8);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("ufrac16"), &NetworkSchemas::ufrac16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("ufrac32"), &NetworkSchemas::ufrac32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("degrees8"), &NetworkSchemas::degrees8);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("degrees16"), &NetworkSchemas::degrees16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("degrees32"), &NetworkSchemas::degrees32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("radians8"), &NetworkSchemas::radians8);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("radians16"), &NetworkSchemas::radians16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("radians32"), &NetworkSchemas::radians32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec2t", "component_serializer"), &NetworkSchemas::vec2t);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec2f16"), &NetworkSchemas::vec2f16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec2f32"), &NetworkSchemas::vec2f32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec2f64"), &NetworkSchemas::vec2f64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec3t", "component_serializer"), &NetworkSchemas::vec3t);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec3f16"), &NetworkSchemas::vec3f16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec3f32"), &NetworkSchemas::vec3f32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec3f64"), &NetworkSchemas::vec3f64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec4t", "component_serializer"), &NetworkSchemas::vec4t);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec4f16"), &NetworkSchemas::vec4f16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec4f32"), &NetworkSchemas::vec4f32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("vec4f64"), &NetworkSchemas::vec4f64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal2t", "component_serializer"), &NetworkSchemas::normal2t);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal2f16"), &NetworkSchemas::normal2f16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal2f32"), &NetworkSchemas::normal2f32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal2f64"), &NetworkSchemas::normal2f64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal3t", "component_serializer"), &NetworkSchemas::normal3t);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal3f16"), &NetworkSchemas::normal3f16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal3f32"), &NetworkSchemas::normal3f32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("normal3f64"), &NetworkSchemas::normal3f64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("quatt", "component_serializer"), &NetworkSchemas::quatt);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("quatf16"), &NetworkSchemas::quatf16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("quatf32"), &NetworkSchemas::quatf32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("quatf64"), &NetworkSchemas::quatf64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform2t", "component_serializer"), &NetworkSchemas::transform2t);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform2f16"), &NetworkSchemas::transform2f16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform2f32"), &NetworkSchemas::transform2f32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform2f64"), &NetworkSchemas::transform2f64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform3t", "component_serializer"), &NetworkSchemas::transform3t);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform3f16"), &NetworkSchemas::transform3f16);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform3f32"), &NetworkSchemas::transform3f32);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("transform3f64"), &NetworkSchemas::transform3f64);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("array_of", "item_serializer", "size_serializer"), &NetworkSchemas::array_of);
		ClassDB::bind_static_method("NetworkSchemas", D_METHOD("dictionary", "key_serializer", "value_serializer", "size_serializer"), &NetworkSchemas::dictionary);
	};

public:
	NetworkSchemas() {};
	~NetworkSchemas() {};
	static Ref<NetworkSchemaSerializer> variant() {
		Ref<_VariantSerializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_StringSerializer> string() {
		Ref<_StringSerializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_BoolSerializer> bool8() {
		Ref<_BoolSerializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Uint8Serializer> uint8() {
		Ref<_Uint8Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Uint16Serializer> uint16() {
		Ref<_Uint16Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Uint32Serializer> uint32() {
		Ref<_Uint32Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Uint64Serializer> uint64() {
		Ref<_Uint64Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Int8Serializer> int8() {
		Ref<_Int8Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Int16Serializer> int16() {
		Ref<_Int16Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Int32Serializer> int32() {
		Ref<_Int32Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Int64Serializer> int64() {
		Ref<_Int64Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Float16Serializer> float16() {
		Ref<_Float16Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Float32Serializer> float32() {
		Ref<_Float32Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_Float64Serializer> float64() {
		Ref<_Float64Serializer> ref;
		ref.instantiate();
		return ref;
	}

	static Ref<_QuantizingSerializer> sfrac8() {
		return _QuantizingSerializer::new_(uint8(), -1., 1., 0, 0xFF);
	}

	static Ref<_QuantizingSerializer> sfrac16() {
		return _QuantizingSerializer::new_(uint16(), -1., 1., 0, 0xFFFF);
	}

	static Ref<_QuantizingSerializer> sfrac32() {
		return _QuantizingSerializer::new_(uint32(), -1., 1., 0, 0xFFFFFFFF);
	}

	static Ref<_QuantizingSerializer> ufrac8() {
		return _QuantizingSerializer::new_(uint8(), 0., 1., 0, 0xFF);
	}

	static Ref<_QuantizingSerializer> ufrac16() {
		return _QuantizingSerializer::new_(uint16(), 0., 1., 0, 0xFFFF);
	}

	static Ref<_QuantizingSerializer> ufrac32() {
		return _QuantizingSerializer::new_(uint32(), 0., 1., 0, 0xFFFFFFFF);
	}

	static Ref<_ModuloSerializer> degrees8() {
		return _ModuloSerializer::new_(uint8(), 360., 0xFF);
	}

	static Ref<_ModuloSerializer> degrees16() {
		return _ModuloSerializer::new_(uint16(), 360., 0xFFFF);
	}

	static Ref<_ModuloSerializer> degrees32() {
		return _ModuloSerializer::new_(uint32(), 360., 0xFFFFFFFF);
	}

	static Ref<_ModuloSerializer> radians8() {
		return _ModuloSerializer::new_(uint8(), Math_TAU, 0xFF);
	}

	static Ref<_ModuloSerializer> radians16() {
		return _ModuloSerializer::new_(uint16(), Math_TAU, 0xFFFF);
	}

	static Ref<_ModuloSerializer> radians32() {
		return _ModuloSerializer::new_(uint32(), Math_TAU, 0xFFFFFFFF);
	}

	static Ref<_GenericVec2Serializer> vec2t(Ref<NetworkSchemaSerializer> component_serializer) {
		return _GenericVec2Serializer::new_(component_serializer);
	}

	static Ref<_GenericVec2Serializer> vec2f16() {
		return vec2t(float16());
	}

	static Ref<_GenericVec2Serializer> vec2f32() {
		return vec2t(float32());
	}

	static Ref<_GenericVec2Serializer> vec2f64() {
		return vec2t(float64());
	}

	static Ref<_GenericVec3Serializer> vec3t(Ref<NetworkSchemaSerializer> component_serializer) {
		return _GenericVec3Serializer::new_(component_serializer);
	}

	static Ref<_GenericVec3Serializer> vec3f16() {
		return vec3t(float16());
	}

	static Ref<_GenericVec3Serializer> vec3f32() {
		return vec3t(float32());
	}

	static Ref<_GenericVec3Serializer> vec3f64() {
		return vec3t(float64());
	}

	static Ref<_GenericVec4Serializer> vec4t(Ref<NetworkSchemaSerializer> component_serializer) {
		return _GenericVec4Serializer::new_(component_serializer);
	}

	static Ref<_GenericVec4Serializer> vec4f16() {
		return vec4t(float16());
	}

	static Ref<_GenericVec4Serializer> vec4f32() {
		return vec4t(float32());
	}

	static Ref<_GenericVec4Serializer> vec4f64() {
		return vec4t(float64());
	}

	static Ref<_Normal2Serializer> normal2t(Ref<NetworkSchemaSerializer> component_serializer) {
		return _Normal2Serializer::new_(component_serializer);
	}

	static Ref<_Normal2Serializer> normal2f16() {
		return normal2t(float16());
	}

	static Ref<_Normal2Serializer> normal2f32() {
		return normal2t(float32());
	}

	static Ref<_Normal2Serializer> normal2f64() {
		return normal2t(float64());
	}

	static Ref<_Normal3Serializer> normal3t(Ref<NetworkSchemaSerializer> component_serializer) {
		return _Normal3Serializer::new_(component_serializer);
	}

	static Ref<_Normal3Serializer> normal3f16() {
		return normal3t(float16());
	}

	static Ref<_Normal3Serializer> normal3f32() {
		return normal3t(float32());
	}

	static Ref<_Normal3Serializer> normal3f64() {
		return normal3t(float64());
	}

	static Ref<_GenericQuaternionSerializer> quatt(Ref<NetworkSchemaSerializer> component_serializer) {
		return _GenericQuaternionSerializer::new_(component_serializer);
	}

	static Ref<_GenericQuaternionSerializer> quatf16() {
		return quatt(float16());
	}

	static Ref<_GenericQuaternionSerializer> quatf32() {
		return quatt(float32());
	}

	static Ref<_GenericQuaternionSerializer> quatf64() {
		return quatt(float64());
	}

	static Ref<_GenericTransform2DSerializer> transform2t(Ref<NetworkSchemaSerializer> component_serializer) {
		return _GenericTransform2DSerializer::new_(component_serializer);
	}

	static Ref<_GenericTransform2DSerializer> transform2f16() {
		return transform2t(float16());
	}

	static Ref<_GenericTransform2DSerializer> transform2f32() {
		return transform2t(float32());
	}

	static Ref<_GenericTransform2DSerializer> transform2f64() {
		return transform2t(float64());
	}

	static Ref<_GenericTransform3DSerializer> transform3t(Ref<NetworkSchemaSerializer> component_serializer) {
		return _GenericTransform3DSerializer::new_(component_serializer);
	}

	static Ref<_GenericTransform3DSerializer> transform3f16() {
		return transform3t(float16());
	}

	static Ref<_GenericTransform3DSerializer> transform3f32() {
		return transform3t(float32());
	}

	static Ref<_GenericTransform3DSerializer> transform3f64() {
		return transform3t(float64());
	}
	static Ref<_ArraySerializer> array_of(Ref<NetworkSchemaSerializer> item_serializer = variant(), Ref<NetworkSchemaSerializer> size_serializer = uint16()) {
		return _ArraySerializer::new_(item_serializer, size_serializer);
	}
	static Ref<NetworkSchemaSerializer> dictionary(Ref<NetworkSchemaSerializer> key_serializer = variant(),
			Ref<NetworkSchemaSerializer> value_serializer = variant(),
			Ref<NetworkSchemaSerializer> size_serializer = uint16()) {
		return _DictionarySerializer::new_(key_serializer, value_serializer, size_serializer);
	};
};
