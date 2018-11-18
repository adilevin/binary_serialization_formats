// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/messages_v1.proto

#ifndef PROTOBUF_INCLUDED_proto_2fmessages_5fv1_2eproto
#define PROTOBUF_INCLUDED_proto_2fmessages_5fv1_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_proto_2fmessages_5fv1_2eproto 

namespace protobuf_proto_2fmessages_5fv1_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_proto_2fmessages_5fv1_2eproto
class Group;
class GroupDefaultTypeInternal;
extern GroupDefaultTypeInternal _Group_default_instance_;
class Person;
class PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
namespace google {
namespace protobuf {
template<> ::Group* Arena::CreateMaybeMessage<::Group>(Arena*);
template<> ::Person* Arena::CreateMaybeMessage<::Person>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class Person : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Person) */ {
 public:
  Person();
  virtual ~Person();

  Person(const Person& from);

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Person(Person&& from) noexcept
    : Person() {
    *this = ::std::move(from);
  }

  inline Person& operator=(Person&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Person& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
               &_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Person* other);
  friend void swap(Person& a, Person& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Person* New() const final {
    return CreateMaybeMessage<Person>(NULL);
  }

  Person* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Person>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Person& from);
  void MergeFrom(const Person& from);
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
  void InternalSwap(Person* other);
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

  // string firstName = 1;
  void clear_firstname();
  static const int kFirstNameFieldNumber = 1;
  const ::std::string& firstname() const;
  void set_firstname(const ::std::string& value);
  #if LANG_CXX11
  void set_firstname(::std::string&& value);
  #endif
  void set_firstname(const char* value);
  void set_firstname(const char* value, size_t size);
  ::std::string* mutable_firstname();
  ::std::string* release_firstname();
  void set_allocated_firstname(::std::string* firstname);

  // string lastName = 2;
  void clear_lastname();
  static const int kLastNameFieldNumber = 2;
  const ::std::string& lastname() const;
  void set_lastname(const ::std::string& value);
  #if LANG_CXX11
  void set_lastname(::std::string&& value);
  #endif
  void set_lastname(const char* value);
  void set_lastname(const char* value, size_t size);
  ::std::string* mutable_lastname();
  ::std::string* release_lastname();
  void set_allocated_lastname(::std::string* lastname);

  // int32 age = 3;
  void clear_age();
  static const int kAgeFieldNumber = 3;
  ::google::protobuf::int32 age() const;
  void set_age(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Person)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr firstname_;
  ::google::protobuf::internal::ArenaStringPtr lastname_;
  ::google::protobuf::int32 age_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_proto_2fmessages_5fv1_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Group : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Group) */ {
 public:
  Group();
  virtual ~Group();

  Group(const Group& from);

  inline Group& operator=(const Group& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Group(Group&& from) noexcept
    : Group() {
    *this = ::std::move(from);
  }

  inline Group& operator=(Group&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Group& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Group* internal_default_instance() {
    return reinterpret_cast<const Group*>(
               &_Group_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Group* other);
  friend void swap(Group& a, Group& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Group* New() const final {
    return CreateMaybeMessage<Group>(NULL);
  }

  Group* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Group>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Group& from);
  void MergeFrom(const Group& from);
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
  void InternalSwap(Group* other);
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

  // repeated .Person individuals = 1;
  int individuals_size() const;
  void clear_individuals();
  static const int kIndividualsFieldNumber = 1;
  ::Person* mutable_individuals(int index);
  ::google::protobuf::RepeatedPtrField< ::Person >*
      mutable_individuals();
  const ::Person& individuals(int index) const;
  ::Person* add_individuals();
  const ::google::protobuf::RepeatedPtrField< ::Person >&
      individuals() const;

  // @@protoc_insertion_point(class_scope:Group)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::Person > individuals_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_proto_2fmessages_5fv1_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Person

// string firstName = 1;
inline void Person::clear_firstname() {
  firstname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Person::firstname() const {
  // @@protoc_insertion_point(field_get:Person.firstName)
  return firstname_.GetNoArena();
}
inline void Person::set_firstname(const ::std::string& value) {
  
  firstname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Person.firstName)
}
#if LANG_CXX11
inline void Person::set_firstname(::std::string&& value) {
  
  firstname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Person.firstName)
}
#endif
inline void Person::set_firstname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  firstname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Person.firstName)
}
inline void Person::set_firstname(const char* value, size_t size) {
  
  firstname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Person.firstName)
}
inline ::std::string* Person::mutable_firstname() {
  
  // @@protoc_insertion_point(field_mutable:Person.firstName)
  return firstname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Person::release_firstname() {
  // @@protoc_insertion_point(field_release:Person.firstName)
  
  return firstname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Person::set_allocated_firstname(::std::string* firstname) {
  if (firstname != NULL) {
    
  } else {
    
  }
  firstname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), firstname);
  // @@protoc_insertion_point(field_set_allocated:Person.firstName)
}

// string lastName = 2;
inline void Person::clear_lastname() {
  lastname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Person::lastname() const {
  // @@protoc_insertion_point(field_get:Person.lastName)
  return lastname_.GetNoArena();
}
inline void Person::set_lastname(const ::std::string& value) {
  
  lastname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Person.lastName)
}
#if LANG_CXX11
inline void Person::set_lastname(::std::string&& value) {
  
  lastname_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Person.lastName)
}
#endif
inline void Person::set_lastname(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  lastname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Person.lastName)
}
inline void Person::set_lastname(const char* value, size_t size) {
  
  lastname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Person.lastName)
}
inline ::std::string* Person::mutable_lastname() {
  
  // @@protoc_insertion_point(field_mutable:Person.lastName)
  return lastname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Person::release_lastname() {
  // @@protoc_insertion_point(field_release:Person.lastName)
  
  return lastname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Person::set_allocated_lastname(::std::string* lastname) {
  if (lastname != NULL) {
    
  } else {
    
  }
  lastname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), lastname);
  // @@protoc_insertion_point(field_set_allocated:Person.lastName)
}

// int32 age = 3;
inline void Person::clear_age() {
  age_ = 0;
}
inline ::google::protobuf::int32 Person::age() const {
  // @@protoc_insertion_point(field_get:Person.age)
  return age_;
}
inline void Person::set_age(::google::protobuf::int32 value) {
  
  age_ = value;
  // @@protoc_insertion_point(field_set:Person.age)
}

// -------------------------------------------------------------------

// Group

// repeated .Person individuals = 1;
inline int Group::individuals_size() const {
  return individuals_.size();
}
inline void Group::clear_individuals() {
  individuals_.Clear();
}
inline ::Person* Group::mutable_individuals(int index) {
  // @@protoc_insertion_point(field_mutable:Group.individuals)
  return individuals_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::Person >*
Group::mutable_individuals() {
  // @@protoc_insertion_point(field_mutable_list:Group.individuals)
  return &individuals_;
}
inline const ::Person& Group::individuals(int index) const {
  // @@protoc_insertion_point(field_get:Group.individuals)
  return individuals_.Get(index);
}
inline ::Person* Group::add_individuals() {
  // @@protoc_insertion_point(field_add:Group.individuals)
  return individuals_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Person >&
Group::individuals() const {
  // @@protoc_insertion_point(field_list:Group.individuals)
  return individuals_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_proto_2fmessages_5fv1_2eproto
