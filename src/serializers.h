#pragma once

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/stream_peer_buffer.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/templates/hash_set.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/vector3.hpp>
using namespace godot;

class NetworkSchemaSerializer : public RefCounted {
	GDCLASS(NetworkSchemaSerializer, RefCounted);

protected:
	static void _bind_methods() {};

public:
	NetworkSchemaSerializer() {};
	~NetworkSchemaSerializer() {};
	virtual void encode(Variant value, Ref<StreamPeerBuffer> &b) {
	}
	// Decode a value from [param buffer] and return it
	virtual Variant decode(Ref<StreamPeerBuffer> &b) {
		return NULL;
	}
};

class _VariantSerializer : public NetworkSchemaSerializer {
	GDCLASS(_VariantSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_VariantSerializer() {};
	~_VariantSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		b->put_var(v, false);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return b->get_var(false);
	}
};

class _StringSerializer : public NetworkSchemaSerializer {
	GDCLASS(_StringSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_StringSerializer() {};
	~_StringSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		b->put_utf8_string(v.stringify());
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return b->get_utf8_string();
	}
};

class _BoolSerializer : public NetworkSchemaSerializer {
	GDCLASS(_BoolSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_BoolSerializer() {};
	~_BoolSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_u8(v ? 1 : 0); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_u8() > 0; }
};

class _Uint8Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Uint8Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Uint8Serializer() {};
	~_Uint8Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_u8(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_u8(); }
};

class _Uint16Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Uint16Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Uint16Serializer() {};
	~_Uint16Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_u16(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_u16(); }
};

class _Uint32Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Uint32Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Uint32Serializer() {};
	~_Uint32Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_u32(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_u32(); }
};

class _Uint64Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Uint64Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Uint64Serializer() {};
	~_Uint64Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_u64(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_u64(); }
};

class _Int8Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Int8Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Int8Serializer() {};
	~_Int8Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_8(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_8(); }
};

class _Int16Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Int16Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Int16Serializer() {};
	~_Int16Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_16(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_16(); }
};

class _Int32Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Int32Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Int32Serializer() {};
	~_Int32Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_32(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_32(); }
};

class _Int64Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Int64Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Int64Serializer() {};
	~_Int64Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_64(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_64(); }
};

class _Float16Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Float16Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Float16Serializer() {};
	~_Float16Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		if (static_cast<int>(Engine::get_singleton()->get_version_info()["hex"]) >= 0x040400) {
			b->put_half(v);
		} else {
			b->put_float(v);
		}
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		if (static_cast<int>(Engine::get_singleton()->get_version_info()["hex"]) >= 0x040400) {
			return b->get_half();
		} else {
			return b->get_float();
		}
	}
};

class _Float32Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Float32Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Float32Serializer() {};
	~_Float32Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_float(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_float(); }
};

class _Float64Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Float64Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {};

public:
	_Float64Serializer() {};
	~_Float64Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) { b->put_double(v); }
	Variant decode(Ref<StreamPeerBuffer> &b) { return b->get_double(); }
};

class _GenericVec2Serializer : public NetworkSchemaSerializer {
	GDCLASS(_GenericVec2Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_GenericVec2Serializer", D_METHOD("new_", "p_component"), &_GenericVec2Serializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;
	static Ref<_GenericVec2Serializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_GenericVec2Serializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_GenericVec2Serializer() {};
	~_GenericVec2Serializer() {};

	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Vector2 v2 = v;
		component->encode(v2.x, b);
		component->encode(v2.y, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Vector2(component->decode(b), component->decode(b));
	}
};

class _GenericVec3Serializer : public NetworkSchemaSerializer {
	GDCLASS(_GenericVec3Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_GenericVec3Serializer", D_METHOD("new_", "p_component"), &_GenericVec3Serializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;

	static Ref<_GenericVec3Serializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_GenericVec3Serializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_GenericVec3Serializer() {};
	~_GenericVec3Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Vector3 v3 = v;
		component->encode(v3.x, b);
		component->encode(v3.y, b);
		component->encode(v3.z, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Vector3(component->decode(b), component->decode(b), component->decode(b));
	}
};

class _Normal2Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Normal2Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_Normal2Serializer", D_METHOD("new_", "p_component"), &_Normal2Serializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;

	static Ref<_Normal2Serializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_Normal2Serializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_Normal2Serializer() {};
	~_Normal2Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		component->encode(static_cast<Vector2>(v).angle(), b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Vector2(1, 0).rotated(component->decode(b));
	}
};

class _Normal3Serializer : public NetworkSchemaSerializer {
	GDCLASS(_Normal3Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_Normal3Serializer", D_METHOD("new_", "p_component"), &_Normal3Serializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;

	static Ref<_Normal3Serializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_Normal3Serializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_Normal3Serializer() {};
	~_Normal3Serializer() {};

	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Vector2 uv = static_cast<Vector3>(v).octahedron_encode();
		component->encode(uv.x, b);
		component->encode(uv.y, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Vector3().octahedron_decode(
				Vector2(component->decode(b), component->decode(b)));
	}
};

class _GenericVec4Serializer : public NetworkSchemaSerializer {
	GDCLASS(_GenericVec4Serializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_GenericVec4Serializer", D_METHOD("new_", "p_component"), &_GenericVec4Serializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;
	static Ref<_GenericVec4Serializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_GenericVec4Serializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_GenericVec4Serializer() {};
	~_GenericVec4Serializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Vector4 v4 = static_cast<Vector4>(v);
		component->encode(v4.x, b);
		component->encode(v4.y, b);
		component->encode(v4.z, b);
		component->encode(v4.w, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Vector4(
				component->decode(b), component->decode(b), component->decode(b), component->decode(b));
	}
};

class _GenericQuaternionSerializer : public NetworkSchemaSerializer {
	GDCLASS(_GenericQuaternionSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_GenericQuaternionSerializer", D_METHOD("new_", "p_component"), &_GenericQuaternionSerializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;

	static Ref<_GenericQuaternionSerializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_GenericQuaternionSerializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_GenericQuaternionSerializer() {};
	~_GenericQuaternionSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Quaternion vq = static_cast<Quaternion>(v);
		component->encode(vq.x, b);
		component->encode(vq.y, b);
		component->encode(vq.z, b);
		component->encode(vq.w, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Quaternion(
				component->decode(b), component->decode(b), component->decode(b), component->decode(b));
	}
};

class _GenericTransform2DSerializer : public NetworkSchemaSerializer {
	GDCLASS(_GenericTransform2DSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_GenericTransform2DSerializer", D_METHOD("new_", "p_component"), &_GenericTransform2DSerializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;

	static Ref<_GenericTransform2DSerializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_GenericTransform2DSerializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_GenericTransform2DSerializer() {};
	~_GenericTransform2DSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Transform2D t = static_cast<Transform2D>(v);

		component->encode(t.columns[0][0], b);
		component->encode(t.columns[0][1], b);
		component->encode(t.columns[1][0], b);
		component->encode(t.columns[1][1], b);
		component->encode(t.get_origin().x, b);
		component->encode(t.get_origin().y, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Transform2D(
				Vector2(component->decode(b), component->decode(b)),
				Vector2(component->decode(b), component->decode(b)),
				Vector2(component->decode(b), component->decode(b)));
	}
};

class _GenericTransform3DSerializer : public NetworkSchemaSerializer {
	GDCLASS(_GenericTransform3DSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_GenericTransform3DSerializer", D_METHOD("new_", "p_component"), &_GenericTransform3DSerializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;

	static Ref<_GenericTransform3DSerializer> new_(Ref<NetworkSchemaSerializer> p_component) {
		Ref<_GenericTransform3DSerializer> ref;
		ref.instantiate();
		ref->component = p_component;
		return ref;
	}
	_GenericTransform3DSerializer() {};
	~_GenericTransform3DSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Transform3D t = static_cast<Transform3D>(v);
		component->encode(t.basis.get_column(0).x, b);
		component->encode(t.basis.get_column(0).y, b);
		component->encode(t.basis.get_column(0).z, b);
		component->encode(t.basis.get_column(1).x, b);
		component->encode(t.basis.get_column(1).y, b);
		component->encode(t.basis.get_column(1).z, b);
		component->encode(t.basis.get_column(2).x, b);
		component->encode(t.basis.get_column(2).y, b);
		component->encode(t.basis.get_column(2).z, b);
		component->encode(t.origin.x, b);
		component->encode(t.origin.y, b);
		component->encode(t.origin.z, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		return Transform3D(
				Basis(
						Vector3(component->decode(b), component->decode(b), component->decode(b)),
						Vector3(component->decode(b), component->decode(b), component->decode(b)),
						Vector3(component->decode(b), component->decode(b), component->decode(b))),
				Vector3(component->decode(b), component->decode(b), component->decode(b)));
	}
};

class _QuantizingSerializer : public NetworkSchemaSerializer {
	GDCLASS(_QuantizingSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_QuantizingSerializer", D_METHOD("new_", "p_component", "p_from_min", "p_from_max", "p_to_min", "p_to_max"), &_QuantizingSerializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;
	Variant from_min;
	Variant from_max;
	Variant to_min;
	Variant to_max;

	static Ref<_QuantizingSerializer> new_(Ref<NetworkSchemaSerializer> p_component, Variant p_from_min, Variant p_from_max, Variant p_to_min, Variant p_to_max) {
		Ref<_QuantizingSerializer> ref;
		ref.instantiate();
		ref->component = p_component;
		ref->from_min = p_from_min;
		ref->from_max = p_from_max;
		ref->to_min = p_to_min;
		ref->to_max = p_to_max;
		return ref;
	}
	_QuantizingSerializer() {};
	~_QuantizingSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Variant f = UtilityFunctions::inverse_lerp(from_min, from_max, v);
		Variant s = UtilityFunctions::lerp(to_min, to_max, f);
		component->encode(s, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		Variant s = component->decode(b);
		Variant f = UtilityFunctions::inverse_lerp(to_min, to_max, s);
		return UtilityFunctions::lerp(from_min, from_max, f);
	}
};

class _ModuloSerializer : public NetworkSchemaSerializer {
	GDCLASS(_ModuloSerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_ModuloSerializer", D_METHOD("new_", "p_component", "p_value_max", "p_component_max"), &_ModuloSerializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;
	double value_max;
	double component_max;

	static Ref<_ModuloSerializer> new_(Ref<NetworkSchemaSerializer> p_component, double p_value_max, double p_component_max) {
		Ref<_ModuloSerializer> ref;
		ref.instantiate();
		ref->component = p_component;
		ref->value_max = p_value_max;
		ref->component_max = p_component_max;
		return ref;
	}
	_ModuloSerializer() {};
	~_ModuloSerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		double f = UtilityFunctions::fposmod(static_cast<double>(v), value_max) / value_max;
		double s = f * component_max;
		component->encode(s, b);
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		double s = static_cast<double>(component->decode(b));
		return (s / component_max) * value_max;
	}
};

class _ArraySerializer : public NetworkSchemaSerializer {
	GDCLASS(_ArraySerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_ArraySerializer", D_METHOD("new_", "p_component", "p_size"), &_ArraySerializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> component;
	Ref<NetworkSchemaSerializer> size;

	static Ref<_ArraySerializer> new_(Ref<NetworkSchemaSerializer> p_component, Ref<NetworkSchemaSerializer> p_size) {
		Ref<_ArraySerializer> ref;
		ref.instantiate();
		ref->component = p_component;
		ref->size = p_size;
		return ref;
	}
	_ArraySerializer() {};
	~_ArraySerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Array array = static_cast<Array>(v);
		size->encode(array.size(), b);
		for (int i = 0; i < array.size(); i++) {
			component->encode(array[i], b);
		}
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		Array array = Array();
		int item_count = static_cast<int>(size->decode(b));
		array.resize(item_count);
		for (int i = 0; i < item_count; i++) {
			array[i] = component->decode(b);
		}
		return array;
	}
};

class _DictionarySerializer : public NetworkSchemaSerializer {
	GDCLASS(_DictionarySerializer, NetworkSchemaSerializer);

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("_ArraySerializer", D_METHOD("new_", "p_key_serializer", "p_value_serializer", "p_size_serializer"), &_ArraySerializer::new_);
	};

public:
	Ref<NetworkSchemaSerializer> key_serializer;
	Ref<NetworkSchemaSerializer> value_serializer;
	Ref<NetworkSchemaSerializer> size_serializer;

	static Ref<_DictionarySerializer> new_(Ref<NetworkSchemaSerializer> p_key_serializer, Ref<NetworkSchemaSerializer> p_value_serializer, Ref<NetworkSchemaSerializer> p_size_serializer) {
		Ref<_DictionarySerializer> ref;
		ref.instantiate();
		ref->key_serializer = p_key_serializer;
		ref->value_serializer = p_value_serializer;
		ref->size_serializer = p_size_serializer;
		return ref;
	}
	_DictionarySerializer() {};
	~_DictionarySerializer() {};
	void encode(Variant v, Ref<StreamPeerBuffer> &b) {
		Dictionary dictionary = static_cast<Dictionary>(v);

		size_serializer->encode(dictionary.size(), b);
		Array keys = dictionary.keys();
		for (int i = 0; i < keys.size(); i++) {
			Variant value = dictionary[keys[i]];
			key_serializer->encode(keys[i], b);
			value_serializer->encode(value, b);
		}
	}
	Variant decode(Ref<StreamPeerBuffer> &b) {
		Dictionary dictionary = {};

		int size = size_serializer->decode(b);
		for (int i = 0; i < size; i++) {
			Variant key = key_serializer->decode(b);
			Variant value = value_serializer->decode(b);
			dictionary[key] = value;
		}
		return dictionary;
	}
};
