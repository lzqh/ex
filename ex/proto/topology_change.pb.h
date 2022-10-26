// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: topology_change.proto

#ifndef PROTOBUF_INCLUDED_topology_5fchange_2eproto
#define PROTOBUF_INCLUDED_topology_5fchange_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "role_attributes.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_topology_5fchange_2eproto 

namespace protobuf_topology_5fchange_2eproto {
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
}  // namespace protobuf_topology_5fchange_2eproto
namespace ex {
namespace proto {
class ChangeMsg;
class ChangeMsgDefaultTypeInternal;
extern ChangeMsgDefaultTypeInternal _ChangeMsg_default_instance_;
}  // namespace proto
}  // namespace ex
namespace google {
namespace protobuf {
template<> ::ex::proto::ChangeMsg* Arena::CreateMaybeMessage<::ex::proto::ChangeMsg>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace ex {
namespace proto {

enum ChangeType {
  CHANGE_NODE = 1,
  CHANGE_CHANNEL = 2,
  CHANGE_SERVICE = 3,
  CHANGE_PARTICIPANT = 4
};
bool ChangeType_IsValid(int value);
const ChangeType ChangeType_MIN = CHANGE_NODE;
const ChangeType ChangeType_MAX = CHANGE_PARTICIPANT;
const int ChangeType_ARRAYSIZE = ChangeType_MAX + 1;

const ::google::protobuf::EnumDescriptor* ChangeType_descriptor();
inline const ::std::string& ChangeType_Name(ChangeType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ChangeType_descriptor(), value);
}
inline bool ChangeType_Parse(
    const ::std::string& name, ChangeType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ChangeType>(
    ChangeType_descriptor(), name, value);
}
enum RoleType {
  ROLE_NODE = 1,
  ROLE_WRITER = 2,
  ROLE_READER = 3,
  ROLE_SERVER = 4,
  ROLE_CLIENT = 5,
  ROLE_PARTICIPANT = 6
};
bool RoleType_IsValid(int value);
const RoleType RoleType_MIN = ROLE_NODE;
const RoleType RoleType_MAX = ROLE_PARTICIPANT;
const int RoleType_ARRAYSIZE = RoleType_MAX + 1;

const ::google::protobuf::EnumDescriptor* RoleType_descriptor();
inline const ::std::string& RoleType_Name(RoleType value) {
  return ::google::protobuf::internal::NameOfEnum(
    RoleType_descriptor(), value);
}
inline bool RoleType_Parse(
    const ::std::string& name, RoleType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<RoleType>(
    RoleType_descriptor(), name, value);
}
enum OperateType {
  OPT_JOIN = 1,
  OPT_LEAVE = 2
};
bool OperateType_IsValid(int value);
const OperateType OperateType_MIN = OPT_JOIN;
const OperateType OperateType_MAX = OPT_LEAVE;
const int OperateType_ARRAYSIZE = OperateType_MAX + 1;

const ::google::protobuf::EnumDescriptor* OperateType_descriptor();
inline const ::std::string& OperateType_Name(OperateType value) {
  return ::google::protobuf::internal::NameOfEnum(
    OperateType_descriptor(), value);
}
inline bool OperateType_Parse(
    const ::std::string& name, OperateType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<OperateType>(
    OperateType_descriptor(), name, value);
}
// ===================================================================

class ChangeMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ex.proto.ChangeMsg) */ {
 public:
  ChangeMsg();
  virtual ~ChangeMsg();

  ChangeMsg(const ChangeMsg& from);

  inline ChangeMsg& operator=(const ChangeMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ChangeMsg(ChangeMsg&& from) noexcept
    : ChangeMsg() {
    *this = ::std::move(from);
  }

  inline ChangeMsg& operator=(ChangeMsg&& from) noexcept {
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
  static const ChangeMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ChangeMsg* internal_default_instance() {
    return reinterpret_cast<const ChangeMsg*>(
               &_ChangeMsg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ChangeMsg* other);
  friend void swap(ChangeMsg& a, ChangeMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ChangeMsg* New() const final {
    return CreateMaybeMessage<ChangeMsg>(NULL);
  }

  ChangeMsg* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ChangeMsg>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ChangeMsg& from);
  void MergeFrom(const ChangeMsg& from);
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
  void InternalSwap(ChangeMsg* other);
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

  // optional .ex.proto.RoleAttributes role_attr = 5;
  bool has_role_attr() const;
  void clear_role_attr();
  static const int kRoleAttrFieldNumber = 5;
  private:
  const ::ex::proto::RoleAttributes& _internal_role_attr() const;
  public:
  const ::ex::proto::RoleAttributes& role_attr() const;
  ::ex::proto::RoleAttributes* release_role_attr();
  ::ex::proto::RoleAttributes* mutable_role_attr();
  void set_allocated_role_attr(::ex::proto::RoleAttributes* role_attr);

  // optional uint64 timestamp = 1;
  bool has_timestamp() const;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  ::google::protobuf::uint64 timestamp() const;
  void set_timestamp(::google::protobuf::uint64 value);

  // optional .ex.proto.RoleType role_type = 4;
  bool has_role_type() const;
  void clear_role_type();
  static const int kRoleTypeFieldNumber = 4;
  ::ex::proto::RoleType role_type() const;
  void set_role_type(::ex::proto::RoleType value);

  // optional .ex.proto.ChangeType change_type = 2;
  bool has_change_type() const;
  void clear_change_type();
  static const int kChangeTypeFieldNumber = 2;
  ::ex::proto::ChangeType change_type() const;
  void set_change_type(::ex::proto::ChangeType value);

  // optional .ex.proto.OperateType operate_type = 3;
  bool has_operate_type() const;
  void clear_operate_type();
  static const int kOperateTypeFieldNumber = 3;
  ::ex::proto::OperateType operate_type() const;
  void set_operate_type(::ex::proto::OperateType value);

  // @@protoc_insertion_point(class_scope:ex.proto.ChangeMsg)
 private:
  void set_has_timestamp();
  void clear_has_timestamp();
  void set_has_change_type();
  void clear_has_change_type();
  void set_has_operate_type();
  void clear_has_operate_type();
  void set_has_role_type();
  void clear_has_role_type();
  void set_has_role_attr();
  void clear_has_role_attr();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::ex::proto::RoleAttributes* role_attr_;
  ::google::protobuf::uint64 timestamp_;
  int role_type_;
  int change_type_;
  int operate_type_;
  friend struct ::protobuf_topology_5fchange_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ChangeMsg

// optional uint64 timestamp = 1;
inline bool ChangeMsg::has_timestamp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ChangeMsg::set_has_timestamp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ChangeMsg::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ChangeMsg::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
  clear_has_timestamp();
}
inline ::google::protobuf::uint64 ChangeMsg::timestamp() const {
  // @@protoc_insertion_point(field_get:ex.proto.ChangeMsg.timestamp)
  return timestamp_;
}
inline void ChangeMsg::set_timestamp(::google::protobuf::uint64 value) {
  set_has_timestamp();
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.ChangeMsg.timestamp)
}

// optional .ex.proto.ChangeType change_type = 2;
inline bool ChangeMsg::has_change_type() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ChangeMsg::set_has_change_type() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ChangeMsg::clear_has_change_type() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ChangeMsg::clear_change_type() {
  change_type_ = 1;
  clear_has_change_type();
}
inline ::ex::proto::ChangeType ChangeMsg::change_type() const {
  // @@protoc_insertion_point(field_get:ex.proto.ChangeMsg.change_type)
  return static_cast< ::ex::proto::ChangeType >(change_type_);
}
inline void ChangeMsg::set_change_type(::ex::proto::ChangeType value) {
  assert(::ex::proto::ChangeType_IsValid(value));
  set_has_change_type();
  change_type_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.ChangeMsg.change_type)
}

// optional .ex.proto.OperateType operate_type = 3;
inline bool ChangeMsg::has_operate_type() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ChangeMsg::set_has_operate_type() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ChangeMsg::clear_has_operate_type() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ChangeMsg::clear_operate_type() {
  operate_type_ = 1;
  clear_has_operate_type();
}
inline ::ex::proto::OperateType ChangeMsg::operate_type() const {
  // @@protoc_insertion_point(field_get:ex.proto.ChangeMsg.operate_type)
  return static_cast< ::ex::proto::OperateType >(operate_type_);
}
inline void ChangeMsg::set_operate_type(::ex::proto::OperateType value) {
  assert(::ex::proto::OperateType_IsValid(value));
  set_has_operate_type();
  operate_type_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.ChangeMsg.operate_type)
}

// optional .ex.proto.RoleType role_type = 4;
inline bool ChangeMsg::has_role_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ChangeMsg::set_has_role_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ChangeMsg::clear_has_role_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ChangeMsg::clear_role_type() {
  role_type_ = 1;
  clear_has_role_type();
}
inline ::ex::proto::RoleType ChangeMsg::role_type() const {
  // @@protoc_insertion_point(field_get:ex.proto.ChangeMsg.role_type)
  return static_cast< ::ex::proto::RoleType >(role_type_);
}
inline void ChangeMsg::set_role_type(::ex::proto::RoleType value) {
  assert(::ex::proto::RoleType_IsValid(value));
  set_has_role_type();
  role_type_ = value;
  // @@protoc_insertion_point(field_set:ex.proto.ChangeMsg.role_type)
}

// optional .ex.proto.RoleAttributes role_attr = 5;
inline bool ChangeMsg::has_role_attr() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ChangeMsg::set_has_role_attr() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ChangeMsg::clear_has_role_attr() {
  _has_bits_[0] &= ~0x00000001u;
}
inline const ::ex::proto::RoleAttributes& ChangeMsg::_internal_role_attr() const {
  return *role_attr_;
}
inline const ::ex::proto::RoleAttributes& ChangeMsg::role_attr() const {
  const ::ex::proto::RoleAttributes* p = role_attr_;
  // @@protoc_insertion_point(field_get:ex.proto.ChangeMsg.role_attr)
  return p != NULL ? *p : *reinterpret_cast<const ::ex::proto::RoleAttributes*>(
      &::ex::proto::_RoleAttributes_default_instance_);
}
inline ::ex::proto::RoleAttributes* ChangeMsg::release_role_attr() {
  // @@protoc_insertion_point(field_release:ex.proto.ChangeMsg.role_attr)
  clear_has_role_attr();
  ::ex::proto::RoleAttributes* temp = role_attr_;
  role_attr_ = NULL;
  return temp;
}
inline ::ex::proto::RoleAttributes* ChangeMsg::mutable_role_attr() {
  set_has_role_attr();
  if (role_attr_ == NULL) {
    auto* p = CreateMaybeMessage<::ex::proto::RoleAttributes>(GetArenaNoVirtual());
    role_attr_ = p;
  }
  // @@protoc_insertion_point(field_mutable:ex.proto.ChangeMsg.role_attr)
  return role_attr_;
}
inline void ChangeMsg::set_allocated_role_attr(::ex::proto::RoleAttributes* role_attr) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(role_attr_);
  }
  if (role_attr) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      role_attr = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, role_attr, submessage_arena);
    }
    set_has_role_attr();
  } else {
    clear_has_role_attr();
  }
  role_attr_ = role_attr;
  // @@protoc_insertion_point(field_set_allocated:ex.proto.ChangeMsg.role_attr)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace ex

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::ex::proto::ChangeType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ex::proto::ChangeType>() {
  return ::ex::proto::ChangeType_descriptor();
}
template <> struct is_proto_enum< ::ex::proto::RoleType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ex::proto::RoleType>() {
  return ::ex::proto::RoleType_descriptor();
}
template <> struct is_proto_enum< ::ex::proto::OperateType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ex::proto::OperateType>() {
  return ::ex::proto::OperateType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_topology_5fchange_2eproto
