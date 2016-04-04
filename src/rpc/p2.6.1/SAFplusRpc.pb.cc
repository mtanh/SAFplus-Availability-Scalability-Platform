// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SAFplusRpc.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "SAFplusRpc.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace SAFplus {
namespace Rpc {

namespace {

const ::google::protobuf::Descriptor* Handle_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Handle_reflection_ = NULL;
const ::google::protobuf::Descriptor* RpcMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RpcMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_SAFplusRpc_2eproto() {
  protobuf_AddDesc_SAFplusRpc_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "SAFplusRpc.proto");
  GOOGLE_CHECK(file != NULL);
  Handle_descriptor_ = file->message_type(0);
  static const int Handle_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Handle, id0_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Handle, id1_),
  };
  Handle_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Handle_descriptor_,
      Handle::default_instance_,
      Handle_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Handle, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Handle, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Handle));
  RpcMessage_descriptor_ = file->message_type(1);
  static const int RpcMessage_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, handle_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, buffer_),
  };
  RpcMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RpcMessage_descriptor_,
      RpcMessage::default_instance_,
      RpcMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RpcMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RpcMessage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_SAFplusRpc_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Handle_descriptor_, &Handle::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RpcMessage_descriptor_, &RpcMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_SAFplusRpc_2eproto() {
  delete Handle::default_instance_;
  delete Handle_reflection_;
  delete RpcMessage::default_instance_;
  delete RpcMessage_reflection_;
}

void protobuf_AddDesc_SAFplusRpc_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020SAFplusRpc.proto\022\013SAFplus.Rpc\"\"\n\006Handl"
    "e\022\013\n\003id0\030\001 \002(\006\022\013\n\003id1\030\002 \002(\006\"i\n\nRpcMessag"
    "e\022\014\n\004type\030\001 \002(\004\022#\n\006handle\030\002 \002(\0132\023.SAFplu"
    "s.Rpc.Handle\022\n\n\002id\030\003 \001(\004\022\014\n\004name\030\004 \001(\t\022\016"
    "\n\006buffer\030\005 \001(\014", 174);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "SAFplusRpc.proto", &protobuf_RegisterTypes);
  Handle::default_instance_ = new Handle();
  RpcMessage::default_instance_ = new RpcMessage();
  Handle::default_instance_->InitAsDefaultInstance();
  RpcMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_SAFplusRpc_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_SAFplusRpc_2eproto {
  StaticDescriptorInitializer_SAFplusRpc_2eproto() {
    protobuf_AddDesc_SAFplusRpc_2eproto();
  }
} static_descriptor_initializer_SAFplusRpc_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Handle::kId0FieldNumber;
const int Handle::kId1FieldNumber;
#endif  // !_MSC_VER

Handle::Handle()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SAFplus.Rpc.Handle)
}

void Handle::InitAsDefaultInstance() {
}

Handle::Handle(const Handle& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SAFplus.Rpc.Handle)
}

void Handle::SharedCtor() {
  _cached_size_ = 0;
  id0_ = GOOGLE_ULONGLONG(0);
  id1_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Handle::~Handle() {
  // @@protoc_insertion_point(destructor:SAFplus.Rpc.Handle)
  SharedDtor();
}

void Handle::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Handle::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Handle::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Handle_descriptor_;
}

const Handle& Handle::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_SAFplusRpc_2eproto();
  return *default_instance_;
}

Handle* Handle::default_instance_ = NULL;

Handle* Handle::New() const {
  return new Handle;
}

void Handle::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Handle*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(id0_, id1_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Handle::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SAFplus.Rpc.Handle)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed64 id0 = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &id0_)));
          set_has_id0();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_id1;
        break;
      }

      // required fixed64 id1 = 2;
      case 2: {
        if (tag == 17) {
         parse_id1:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &id1_)));
          set_has_id1();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SAFplus.Rpc.Handle)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SAFplus.Rpc.Handle)
  return false;
#undef DO_
}

void Handle::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SAFplus.Rpc.Handle)
  // required fixed64 id0 = 1;
  if (has_id0()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->id0(), output);
  }

  // required fixed64 id1 = 2;
  if (has_id1()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(2, this->id1(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SAFplus.Rpc.Handle)
}

::google::protobuf::uint8* Handle::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SAFplus.Rpc.Handle)
  // required fixed64 id0 = 1;
  if (has_id0()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(1, this->id0(), target);
  }

  // required fixed64 id1 = 2;
  if (has_id1()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(2, this->id1(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SAFplus.Rpc.Handle)
  return target;
}

int Handle::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed64 id0 = 1;
    if (has_id0()) {
      total_size += 1 + 8;
    }

    // required fixed64 id1 = 2;
    if (has_id1()) {
      total_size += 1 + 8;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Handle::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Handle* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Handle*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Handle::MergeFrom(const Handle& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id0()) {
      set_id0(from.id0());
    }
    if (from.has_id1()) {
      set_id1(from.id1());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Handle::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Handle::CopyFrom(const Handle& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Handle::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void Handle::Swap(Handle* other) {
  if (other != this) {
    std::swap(id0_, other->id0_);
    std::swap(id1_, other->id1_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Handle::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Handle_descriptor_;
  metadata.reflection = Handle_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RpcMessage::kTypeFieldNumber;
const int RpcMessage::kHandleFieldNumber;
const int RpcMessage::kIdFieldNumber;
const int RpcMessage::kNameFieldNumber;
const int RpcMessage::kBufferFieldNumber;
#endif  // !_MSC_VER

RpcMessage::RpcMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SAFplus.Rpc.RpcMessage)
}

void RpcMessage::InitAsDefaultInstance() {
  handle_ = const_cast< ::SAFplus::Rpc::Handle*>(&::SAFplus::Rpc::Handle::default_instance());
}

RpcMessage::RpcMessage(const RpcMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SAFplus.Rpc.RpcMessage)
}

void RpcMessage::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  type_ = GOOGLE_ULONGLONG(0);
  handle_ = NULL;
  id_ = GOOGLE_ULONGLONG(0);
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  buffer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RpcMessage::~RpcMessage() {
  // @@protoc_insertion_point(destructor:SAFplus.Rpc.RpcMessage)
  SharedDtor();
}

void RpcMessage::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete buffer_;
  }
  if (this != default_instance_) {
    delete handle_;
  }
}

void RpcMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RpcMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RpcMessage_descriptor_;
}

const RpcMessage& RpcMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_SAFplusRpc_2eproto();
  return *default_instance_;
}

RpcMessage* RpcMessage::default_instance_ = NULL;

RpcMessage* RpcMessage::New() const {
  return new RpcMessage;
}

void RpcMessage::Clear() {
  if (_has_bits_[0 / 32] & 31) {
    type_ = GOOGLE_ULONGLONG(0);
    if (has_handle()) {
      if (handle_ != NULL) handle_->::SAFplus::Rpc::Handle::Clear();
    }
    id_ = GOOGLE_ULONGLONG(0);
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    if (has_buffer()) {
      if (buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        buffer_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RpcMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SAFplus.Rpc.RpcMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 type = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &type_)));
          set_has_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_handle;
        break;
      }

      // required .SAFplus.Rpc.Handle handle = 2;
      case 2: {
        if (tag == 18) {
         parse_handle:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_handle()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_id;
        break;
      }

      // optional uint64 id = 3;
      case 3: {
        if (tag == 24) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_name;
        break;
      }

      // optional string name = 4;
      case 4: {
        if (tag == 34) {
         parse_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_buffer;
        break;
      }

      // optional bytes buffer = 5;
      case 5: {
        if (tag == 42) {
         parse_buffer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_buffer()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SAFplus.Rpc.RpcMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SAFplus.Rpc.RpcMessage)
  return false;
#undef DO_
}

void RpcMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SAFplus.Rpc.RpcMessage)
  // required uint64 type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->type(), output);
  }

  // required .SAFplus.Rpc.Handle handle = 2;
  if (has_handle()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->handle(), output);
  }

  // optional uint64 id = 3;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(3, this->id(), output);
  }

  // optional string name = 4;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->name(), output);
  }

  // optional bytes buffer = 5;
  if (has_buffer()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      5, this->buffer(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SAFplus.Rpc.RpcMessage)
}

::google::protobuf::uint8* RpcMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SAFplus.Rpc.RpcMessage)
  // required uint64 type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->type(), target);
  }

  // required .SAFplus.Rpc.Handle handle = 2;
  if (has_handle()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->handle(), target);
  }

  // optional uint64 id = 3;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(3, this->id(), target);
  }

  // optional string name = 4;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->name(), target);
  }

  // optional bytes buffer = 5;
  if (has_buffer()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        5, this->buffer(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SAFplus.Rpc.RpcMessage)
  return target;
}

int RpcMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->type());
    }

    // required .SAFplus.Rpc.Handle handle = 2;
    if (has_handle()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->handle());
    }

    // optional uint64 id = 3;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->id());
    }

    // optional string name = 4;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional bytes buffer = 5;
    if (has_buffer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->buffer());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RpcMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RpcMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RpcMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RpcMessage::MergeFrom(const RpcMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_handle()) {
      mutable_handle()->::SAFplus::Rpc::Handle::MergeFrom(from.handle());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_buffer()) {
      set_buffer(from.buffer());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RpcMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RpcMessage::CopyFrom(const RpcMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RpcMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_handle()) {
    if (!this->handle().IsInitialized()) return false;
  }
  return true;
}

void RpcMessage::Swap(RpcMessage* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(handle_, other->handle_);
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(buffer_, other->buffer_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RpcMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RpcMessage_descriptor_;
  metadata.reflection = RpcMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Rpc
}  // namespace SAFplus

// @@protoc_insertion_point(global_scope)
