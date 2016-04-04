// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SAFplusRpc.proto

#ifndef PROTOBUF_SAFplusRpc_2eproto__INCLUDED
#define PROTOBUF_SAFplusRpc_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace SAFplus {
namespace Rpc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_SAFplusRpc_2eproto();
void protobuf_AssignDesc_SAFplusRpc_2eproto();
void protobuf_ShutdownFile_SAFplusRpc_2eproto();

class Handle;
class RpcMessage;

// ===================================================================

class Handle : public ::google::protobuf::Message {
 public:
  Handle();
  virtual ~Handle();

  Handle(const Handle& from);

  inline Handle& operator=(const Handle& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Handle& default_instance();

  void Swap(Handle* other);

  // implements Message ----------------------------------------------

  Handle* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Handle& from);
  void MergeFrom(const Handle& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required fixed64 id0 = 1;
  inline bool has_id0() const;
  inline void clear_id0();
  static const int kId0FieldNumber = 1;
  inline ::google::protobuf::uint64 id0() const;
  inline void set_id0(::google::protobuf::uint64 value);

  // required fixed64 id1 = 2;
  inline bool has_id1() const;
  inline void clear_id1();
  static const int kId1FieldNumber = 2;
  inline ::google::protobuf::uint64 id1() const;
  inline void set_id1(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:SAFplus.Rpc.Handle)
 private:
  inline void set_has_id0();
  inline void clear_has_id0();
  inline void set_has_id1();
  inline void clear_has_id1();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint64 id0_;
  ::google::protobuf::uint64 id1_;
  friend void  protobuf_AddDesc_SAFplusRpc_2eproto();
  friend void protobuf_AssignDesc_SAFplusRpc_2eproto();
  friend void protobuf_ShutdownFile_SAFplusRpc_2eproto();

  void InitAsDefaultInstance();
  static Handle* default_instance_;
};
// -------------------------------------------------------------------

class RpcMessage : public ::google::protobuf::Message {
 public:
  RpcMessage();
  virtual ~RpcMessage();

  RpcMessage(const RpcMessage& from);

  inline RpcMessage& operator=(const RpcMessage& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RpcMessage& default_instance();

  void Swap(RpcMessage* other);

  // implements Message ----------------------------------------------

  RpcMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RpcMessage& from);
  void MergeFrom(const RpcMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint64 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::uint64 type() const;
  inline void set_type(::google::protobuf::uint64 value);

  // required .SAFplus.Rpc.Handle handle = 2;
  inline bool has_handle() const;
  inline void clear_handle();
  static const int kHandleFieldNumber = 2;
  inline const ::SAFplus::Rpc::Handle& handle() const;
  inline ::SAFplus::Rpc::Handle* mutable_handle();
  inline ::SAFplus::Rpc::Handle* release_handle();
  inline void set_allocated_handle(::SAFplus::Rpc::Handle* handle);

  // optional uint64 id = 3;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 3;
  inline ::google::protobuf::uint64 id() const;
  inline void set_id(::google::protobuf::uint64 value);

  // optional string name = 4;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 4;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional bytes buffer = 5;
  inline bool has_buffer() const;
  inline void clear_buffer();
  static const int kBufferFieldNumber = 5;
  inline const ::std::string& buffer() const;
  inline void set_buffer(const ::std::string& value);
  inline void set_buffer(const char* value);
  inline void set_buffer(const void* value, size_t size);
  inline ::std::string* mutable_buffer();
  inline ::std::string* release_buffer();
  inline void set_allocated_buffer(::std::string* buffer);

  // @@protoc_insertion_point(class_scope:SAFplus.Rpc.RpcMessage)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_handle();
  inline void clear_has_handle();
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_buffer();
  inline void clear_has_buffer();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint64 type_;
  ::SAFplus::Rpc::Handle* handle_;
  ::google::protobuf::uint64 id_;
  ::std::string* name_;
  ::std::string* buffer_;
  friend void  protobuf_AddDesc_SAFplusRpc_2eproto();
  friend void protobuf_AssignDesc_SAFplusRpc_2eproto();
  friend void protobuf_ShutdownFile_SAFplusRpc_2eproto();

  void InitAsDefaultInstance();
  static RpcMessage* default_instance_;
};
// ===================================================================


// ===================================================================

// Handle

// required fixed64 id0 = 1;
inline bool Handle::has_id0() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Handle::set_has_id0() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Handle::clear_has_id0() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Handle::clear_id0() {
  id0_ = GOOGLE_ULONGLONG(0);
  clear_has_id0();
}
inline ::google::protobuf::uint64 Handle::id0() const {
  // @@protoc_insertion_point(field_get:SAFplus.Rpc.Handle.id0)
  return id0_;
}
inline void Handle::set_id0(::google::protobuf::uint64 value) {
  set_has_id0();
  id0_ = value;
  // @@protoc_insertion_point(field_set:SAFplus.Rpc.Handle.id0)
}

// required fixed64 id1 = 2;
inline bool Handle::has_id1() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Handle::set_has_id1() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Handle::clear_has_id1() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Handle::clear_id1() {
  id1_ = GOOGLE_ULONGLONG(0);
  clear_has_id1();
}
inline ::google::protobuf::uint64 Handle::id1() const {
  // @@protoc_insertion_point(field_get:SAFplus.Rpc.Handle.id1)
  return id1_;
}
inline void Handle::set_id1(::google::protobuf::uint64 value) {
  set_has_id1();
  id1_ = value;
  // @@protoc_insertion_point(field_set:SAFplus.Rpc.Handle.id1)
}

// -------------------------------------------------------------------

// RpcMessage

// required uint64 type = 1;
inline bool RpcMessage::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RpcMessage::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RpcMessage::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RpcMessage::clear_type() {
  type_ = GOOGLE_ULONGLONG(0);
  clear_has_type();
}
inline ::google::protobuf::uint64 RpcMessage::type() const {
  // @@protoc_insertion_point(field_get:SAFplus.Rpc.RpcMessage.type)
  return type_;
}
inline void RpcMessage::set_type(::google::protobuf::uint64 value) {
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:SAFplus.Rpc.RpcMessage.type)
}

// required .SAFplus.Rpc.Handle handle = 2;
inline bool RpcMessage::has_handle() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RpcMessage::set_has_handle() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RpcMessage::clear_has_handle() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RpcMessage::clear_handle() {
  if (handle_ != NULL) handle_->::SAFplus::Rpc::Handle::Clear();
  clear_has_handle();
}
inline const ::SAFplus::Rpc::Handle& RpcMessage::handle() const {
  // @@protoc_insertion_point(field_get:SAFplus.Rpc.RpcMessage.handle)
  return handle_ != NULL ? *handle_ : *default_instance_->handle_;
}
inline ::SAFplus::Rpc::Handle* RpcMessage::mutable_handle() {
  set_has_handle();
  if (handle_ == NULL) handle_ = new ::SAFplus::Rpc::Handle;
  // @@protoc_insertion_point(field_mutable:SAFplus.Rpc.RpcMessage.handle)
  return handle_;
}
inline ::SAFplus::Rpc::Handle* RpcMessage::release_handle() {
  clear_has_handle();
  ::SAFplus::Rpc::Handle* temp = handle_;
  handle_ = NULL;
  return temp;
}
inline void RpcMessage::set_allocated_handle(::SAFplus::Rpc::Handle* handle) {
  delete handle_;
  handle_ = handle;
  if (handle) {
    set_has_handle();
  } else {
    clear_has_handle();
  }
  // @@protoc_insertion_point(field_set_allocated:SAFplus.Rpc.RpcMessage.handle)
}

// optional uint64 id = 3;
inline bool RpcMessage::has_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RpcMessage::set_has_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RpcMessage::clear_has_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RpcMessage::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::uint64 RpcMessage::id() const {
  // @@protoc_insertion_point(field_get:SAFplus.Rpc.RpcMessage.id)
  return id_;
}
inline void RpcMessage::set_id(::google::protobuf::uint64 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:SAFplus.Rpc.RpcMessage.id)
}

// optional string name = 4;
inline bool RpcMessage::has_name() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RpcMessage::set_has_name() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RpcMessage::clear_has_name() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RpcMessage::clear_name() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& RpcMessage::name() const {
  // @@protoc_insertion_point(field_get:SAFplus.Rpc.RpcMessage.name)
  return *name_;
}
inline void RpcMessage::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set:SAFplus.Rpc.RpcMessage.name)
}
inline void RpcMessage::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(value);
  // @@protoc_insertion_point(field_set_char:SAFplus.Rpc.RpcMessage.name)
}
inline void RpcMessage::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:SAFplus.Rpc.RpcMessage.name)
}
inline ::std::string* RpcMessage::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:SAFplus.Rpc.RpcMessage.name)
  return name_;
}
inline ::std::string* RpcMessage::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void RpcMessage::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:SAFplus.Rpc.RpcMessage.name)
}

// optional bytes buffer = 5;
inline bool RpcMessage::has_buffer() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void RpcMessage::set_has_buffer() {
  _has_bits_[0] |= 0x00000010u;
}
inline void RpcMessage::clear_has_buffer() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void RpcMessage::clear_buffer() {
  if (buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buffer_->clear();
  }
  clear_has_buffer();
}
inline const ::std::string& RpcMessage::buffer() const {
  // @@protoc_insertion_point(field_get:SAFplus.Rpc.RpcMessage.buffer)
  return *buffer_;
}
inline void RpcMessage::set_buffer(const ::std::string& value) {
  set_has_buffer();
  if (buffer_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buffer_ = new ::std::string;
  }
  buffer_->assign(value);
  // @@protoc_insertion_point(field_set:SAFplus.Rpc.RpcMessage.buffer)
}
inline void RpcMessage::set_buffer(const char* value) {
  set_has_buffer();
  if (buffer_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buffer_ = new ::std::string;
  }
  buffer_->assign(value);
  // @@protoc_insertion_point(field_set_char:SAFplus.Rpc.RpcMessage.buffer)
}
inline void RpcMessage::set_buffer(const void* value, size_t size) {
  set_has_buffer();
  if (buffer_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buffer_ = new ::std::string;
  }
  buffer_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:SAFplus.Rpc.RpcMessage.buffer)
}
inline ::std::string* RpcMessage::mutable_buffer() {
  set_has_buffer();
  if (buffer_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buffer_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:SAFplus.Rpc.RpcMessage.buffer)
  return buffer_;
}
inline ::std::string* RpcMessage::release_buffer() {
  clear_has_buffer();
  if (buffer_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = buffer_;
    buffer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void RpcMessage::set_allocated_buffer(::std::string* buffer) {
  if (buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete buffer_;
  }
  if (buffer) {
    set_has_buffer();
    buffer_ = buffer;
  } else {
    clear_has_buffer();
    buffer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:SAFplus.Rpc.RpcMessage.buffer)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Rpc
}  // namespace SAFplus

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_SAFplusRpc_2eproto__INCLUDED
