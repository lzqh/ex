// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: role_attributes.proto

#ifndef PROTOBUF_INCLUDED_role_5fattributes_2eproto
#define PROTOBUF_INCLUDED_role_5fattributes_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_role_5fattributes_2eproto 

namespace protobuf_role_5fattributes_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_role_5fattributes_2eproto
namespace ex {
namespace proto {
class RoleAttributes;
class RoleAttributesDefaultTypeInternal;
extern RoleAttributesDefaultTypeInternal _RoleAttributes_default_instance_;
}  // namespace proto
}  // namespace ex
namespace google {
namespace protobuf {
template<> ::ex::proto::RoleAttributes* Arena::CreateMaybeMessage<::ex::proto::RoleAttributes>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace ex {
namespace proto {

// ===================================================================

class RoleAttributes : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ex.proto.RoleAttributes) */ {
 public:
  RoleAttributes();
  virtual ~RoleAttributes();

  RoleAttributes(const RoleAttributes& from);

  inline RoleAttributes& operator=(const RoleAttributes& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RoleAttributes(RoleAttributes&& from) noexcept
    : RoleAttributes() {
    *this = ::std::move(from);
  }

  inline RoleAttributes& operator=(RoleAttributes&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RoleAttributes& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RoleAttributes* internal_default_instance() {
    return reinterpret_cast<const RoleAttributes*>(
               &_RoleAttributes_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(RoleAttributes* other);
  friend void swap(RoleAttributes& a, RoleAttributes& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RoleAttributes* New() const final {
    return CreateMaybeMessage<RoleAttributes>(NULL);
  }

  RoleAttributes* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RoleAttributes>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RoleAttributes& from);
  void MergeFrom(const RoleAttributes& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RoleAttributes* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string host_ip = 1;
  bool has_host_ip() const;
  void clear_host_ip();
  static const int kHostIpFieldNumber = 1;
  const ::std::string& host_ip() const;
  void set_host_ip(const ::std::string& value);
  #if LANG_CXX11
  void set_host_ip(::std::string&& value);
  #endif
  void set_host_ip(const char* value);
  void set_host_ip(const char* value, size_t size);
  ::std::string* mutable_host_ip();
  ::std::string* release_host_ip();
  void set_allocated_host_ip(::std::string* host_ip);

  // optional string node_name = 3;
  bool has_node_name() const;
  void clear_node_name();
  static const int kNodeNameFieldNumber = 3;
  const ::std::string& node_name() const;
  void set_node_name(const ::std::string& value);
  #if LANG_CXX11
  void set_node_name(::std::string&& value);
  #endif
  void set_node_name(const char* value);
  void set_node_name(const char* value, size_t size);
  ::std::string* mutable_node_name();
  ::std::string* release_node_name();
  void set_allocated_node_name(::std::string* node_name);

  // optional string channel_name = 5;
  bool has_channel_name() const;
  void clear_channel_name();
  static const int kChannelNameFieldNumber = 5;
  const ::std::string& channel_name() const;
  void set_channel_name(const ::std::string& value);
  #if LANG_CXX11
  void set_channel_name(::std::string&& value);
  #endif
  void set_channel_name(const char* value);
  void set_channel_name(const char* value, size_t size);
  ::std::string* mutable_channel_name();
  ::std::string* release_channel_name();
  void set_allocated_channel_name(::std::string* channel_name);

  // optional uint64 process_id = 2;
  bool has_process_id() const;
  void clear_process_id();
  static const int kProcessIdFieldNumber = 2;
  ::google::protobuf::uint64 process_id() const;
  void set_process_id(::google::protobuf::uint64 value);

  // optional uint64 node_id = 4;
  bool has_node_id() const;
  void clear_node_id();
  static const int kNodeIdFieldNumber = 4;
  ::google::protobuf::uint64 node_id() const;
  void set_node_id(::google::protobuf::uint64 value);

  // optional uint64 channel_id = 6;
  bool has_channel_id() const;
  void clear_channel_id();
  static const int kChannelIdFieldNumber = 6;
  ::google::protobuf::uint64 channel_id() const;
  void set_channel_id(::google::protobuf::uint64 value);

  // optional uint64 id = 7;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 7;
  ::google::protobuf::uint64 id() const;
  void set_id(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:ex.proto.RoleAttributes)
 private:
  void set_has_host_ip();
  void clear_has_host_ip();
  void set_has_process_id();
  void clear_has_process_id();
  void set_has_node_name();
  void clear_has_node_name();
  void set_has_node_id();
  void clear_has_node_id();
  void set_has_channel_name();
  void clear_has_channel_name();
  void set_has_channel_id();
  void clear_has_channel_id();
  void set_has_id();
  void clear_has_id();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr host_ip_;
  ::google::protobuf::internal::ArenaStringPtr node_name_;
  ::google::protobuf::internal::ArenaStringPtr channel_name_;
  ::google::protobuf::uint64 process_id_;
  ::google::protobuf::uint64 node_id_;
  ::google::protobuf::uint64 channel_id_;
  ::google::protobuf::uint64 id_;
  friend struct ::protobuf_role_5fattributes_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RoleAttributes

// optional string host_ip = 1;
inline bool RoleAttributes::has_host_ip() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RoleAttributes::set_has_host_ip() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RoleAttributes::clear_has_host_ip() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RoleAttributes::clear_host_ip() {
  host_ip_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_host_ip();
}
inline const ::std::string& RoleAttributes::host_ip() const {
  // @@protoc_insertion_point(field_get:ex.proto.RoleAttributes.host_ip)
  return host_ip_.GetNoArena();
}
inline void RoleAttributes::set_host_ip(const ::std::string& value) {
  set_has_host_ip();
  host_ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ex.proto.RoleAttributes.host_ip)
}
#if LANG_CXX11
inline void RoleAttributes::set_host_ip(::std::string&& value) {
  set_has_host_ip();
  host_ip_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ex.proto.RoleAttributes.host_ip)
}
#endif
inline void RoleAttributes::set_host_ip(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_host_ip();
  host_ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ex.proto.RoleAttributes.host_ip)
}
inline void RoleAttributes::set_host_ip(const char* value, size_t size) {
  set_has_host_ip();
  host_ip_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ex.proto.RoleAttributes.host_ip)
}
inline ::std::string* RoleAttributes::mutable_host_ip() {
  set_has_host_ip();
  // @@protoc_insertion_point(field_mutable:ex.proto.RoleAttributes.host_ip)
  return host_ip_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RoleAttributes::release_host_ip() {
  // @@protoc_insertion_point(field_release:ex.proto.RoleAttributes.host_ip)
  if (!has_host_ip()) {
    return NULL;
  }
  clear_has_host_ip();
  return host_ip_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RoleAttributes::set_allocated_host_ip(::std::string* host_ip) {
  if (host_ip != NULL) {
    set_has_host_ip();
  } else {
    clear_has_host_ip();
  }
  host_ip_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), host_ip);
  // @@protoc_insertion_point(field_set_allocated:ex.proto.RoleAttributes.host_ip)
}

// optional uint64 process_id = 2;
inline bool RoleAttributes::has_process_id() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RoleAttributes::set_has_process_id() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RoleAttributes::clear_has_process_id() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RoleAttributes::clear_process_id() {
  process_id_ = GOOGLE_ULONGLONG(0);
  clear_has_process_id();
}
inline ::google::protobuf::uint64 RoleAttributes::process_id() const {
  // @@protoc_insertion_point(field_get:ex.proto.RoleAttributes.process_id)
  return process_id_;
}
inline void RoleAttributes::set_process_id(::google::protobuf::uint64 value) {
  set_has_process_id();
  process_id_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.RoleAttributes.process_id)
}

// optional string node_name = 3;
inline bool RoleAttributes::has_node_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RoleAttributes::set_has_node_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RoleAttributes::clear_has_node_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RoleAttributes::clear_node_name() {
  node_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_node_name();
}
inline const ::std::string& RoleAttributes::node_name() const {
  // @@protoc_insertion_point(field_get:ex.proto.RoleAttributes.node_name)
  return node_name_.GetNoArena();
}
inline void RoleAttributes::set_node_name(const ::std::string& value) {
  set_has_node_name();
  node_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ex.proto.RoleAttributes.node_name)
}
#if LANG_CXX11
inline void RoleAttributes::set_node_name(::std::string&& value) {
  set_has_node_name();
  node_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ex.proto.RoleAttributes.node_name)
}
#endif
inline void RoleAttributes::set_node_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_node_name();
  node_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ex.proto.RoleAttributes.node_name)
}
inline void RoleAttributes::set_node_name(const char* value, size_t size) {
  set_has_node_name();
  node_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ex.proto.RoleAttributes.node_name)
}
inline ::std::string* RoleAttributes::mutable_node_name() {
  set_has_node_name();
  // @@protoc_insertion_point(field_mutable:ex.proto.RoleAttributes.node_name)
  return node_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RoleAttributes::release_node_name() {
  // @@protoc_insertion_point(field_release:ex.proto.RoleAttributes.node_name)
  if (!has_node_name()) {
    return NULL;
  }
  clear_has_node_name();
  return node_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RoleAttributes::set_allocated_node_name(::std::string* node_name) {
  if (node_name != NULL) {
    set_has_node_name();
  } else {
    clear_has_node_name();
  }
  node_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), node_name);
  // @@protoc_insertion_point(field_set_allocated:ex.proto.RoleAttributes.node_name)
}

// optional uint64 node_id = 4;
inline bool RoleAttributes::has_node_id() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void RoleAttributes::set_has_node_id() {
  _has_bits_[0] |= 0x00000010u;
}
inline void RoleAttributes::clear_has_node_id() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void RoleAttributes::clear_node_id() {
  node_id_ = GOOGLE_ULONGLONG(0);
  clear_has_node_id();
}
inline ::google::protobuf::uint64 RoleAttributes::node_id() const {
  // @@protoc_insertion_point(field_get:ex.proto.RoleAttributes.node_id)
  return node_id_;
}
inline void RoleAttributes::set_node_id(::google::protobuf::uint64 value) {
  set_has_node_id();
  node_id_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.RoleAttributes.node_id)
}

// optional string channel_name = 5;
inline bool RoleAttributes::has_channel_name() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RoleAttributes::set_has_channel_name() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RoleAttributes::clear_has_channel_name() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RoleAttributes::clear_channel_name() {
  channel_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_channel_name();
}
inline const ::std::string& RoleAttributes::channel_name() const {
  // @@protoc_insertion_point(field_get:ex.proto.RoleAttributes.channel_name)
  return channel_name_.GetNoArena();
}
inline void RoleAttributes::set_channel_name(const ::std::string& value) {
  set_has_channel_name();
  channel_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ex.proto.RoleAttributes.channel_name)
}
#if LANG_CXX11
inline void RoleAttributes::set_channel_name(::std::string&& value) {
  set_has_channel_name();
  channel_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ex.proto.RoleAttributes.channel_name)
}
#endif
inline void RoleAttributes::set_channel_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_channel_name();
  channel_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ex.proto.RoleAttributes.channel_name)
}
inline void RoleAttributes::set_channel_name(const char* value, size_t size) {
  set_has_channel_name();
  channel_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ex.proto.RoleAttributes.channel_name)
}
inline ::std::string* RoleAttributes::mutable_channel_name() {
  set_has_channel_name();
  // @@protoc_insertion_point(field_mutable:ex.proto.RoleAttributes.channel_name)
  return channel_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RoleAttributes::release_channel_name() {
  // @@protoc_insertion_point(field_release:ex.proto.RoleAttributes.channel_name)
  if (!has_channel_name()) {
    return NULL;
  }
  clear_has_channel_name();
  return channel_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RoleAttributes::set_allocated_channel_name(::std::string* channel_name) {
  if (channel_name != NULL) {
    set_has_channel_name();
  } else {
    clear_has_channel_name();
  }
  channel_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), channel_name);
  // @@protoc_insertion_point(field_set_allocated:ex.proto.RoleAttributes.channel_name)
}

// optional uint64 channel_id = 6;
inline bool RoleAttributes::has_channel_id() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void RoleAttributes::set_has_channel_id() {
  _has_bits_[0] |= 0x00000020u;
}
inline void RoleAttributes::clear_has_channel_id() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void RoleAttributes::clear_channel_id() {
  channel_id_ = GOOGLE_ULONGLONG(0);
  clear_has_channel_id();
}
inline ::google::protobuf::uint64 RoleAttributes::channel_id() const {
  // @@protoc_insertion_point(field_get:ex.proto.RoleAttributes.channel_id)
  return channel_id_;
}
inline void RoleAttributes::set_channel_id(::google::protobuf::uint64 value) {
  set_has_channel_id();
  channel_id_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.RoleAttributes.channel_id)
}

// optional uint64 id = 7;
inline bool RoleAttributes::has_id() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void RoleAttributes::set_has_id() {
  _has_bits_[0] |= 0x00000040u;
}
inline void RoleAttributes::clear_has_id() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void RoleAttributes::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::uint64 RoleAttributes::id() const {
  // @@protoc_insertion_point(field_get:ex.proto.RoleAttributes.id)
  return id_;
}
inline void RoleAttributes::set_id(::google::protobuf::uint64 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.RoleAttributes.id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace ex

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_role_5fattributes_2eproto
