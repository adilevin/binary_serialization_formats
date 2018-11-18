// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: proto/person.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
/// <summary>Holder for reflection information generated from proto/person.proto</summary>
public static partial class PersonReflection {

  #region Descriptor
  /// <summary>File descriptor for proto/person.proto</summary>
  public static pbr::FileDescriptor Descriptor {
    get { return descriptor; }
  }
  private static pbr::FileDescriptor descriptor;

  static PersonReflection() {
    byte[] descriptorData = global::System.Convert.FromBase64String(
        string.Concat(
          "ChJwcm90by9wZXJzb24ucHJvdG8iOgoGUGVyc29uEhEKCWZpcnN0TmFtZRgB",
          "IAEoCRIQCghsYXN0TmFtZRgCIAEoCRILCgNhZ2UYAyABKAViBnByb3RvMw=="));
    descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
        new pbr::FileDescriptor[] { },
        new pbr::GeneratedClrTypeInfo(null, new pbr::GeneratedClrTypeInfo[] {
          new pbr::GeneratedClrTypeInfo(typeof(global::Person), global::Person.Parser, new[]{ "FirstName", "LastName", "Age" }, null, null, null)
        }));
  }
  #endregion

}
#region Messages
public sealed partial class Person : pb::IMessage<Person> {
  private static readonly pb::MessageParser<Person> _parser = new pb::MessageParser<Person>(() => new Person());
  private pb::UnknownFieldSet _unknownFields;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pb::MessageParser<Person> Parser { get { return _parser; } }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public static pbr::MessageDescriptor Descriptor {
    get { return global::PersonReflection.Descriptor.MessageTypes[0]; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  pbr::MessageDescriptor pb::IMessage.Descriptor {
    get { return Descriptor; }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public Person() {
    OnConstruction();
  }

  partial void OnConstruction();

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public Person(Person other) : this() {
    firstName_ = other.firstName_;
    lastName_ = other.lastName_;
    age_ = other.age_;
    _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public Person Clone() {
    return new Person(this);
  }

  /// <summary>Field number for the "firstName" field.</summary>
  public const int FirstNameFieldNumber = 1;
  private string firstName_ = "";
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public string FirstName {
    get { return firstName_; }
    set {
      firstName_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
    }
  }

  /// <summary>Field number for the "lastName" field.</summary>
  public const int LastNameFieldNumber = 2;
  private string lastName_ = "";
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public string LastName {
    get { return lastName_; }
    set {
      lastName_ = pb::ProtoPreconditions.CheckNotNull(value, "value");
    }
  }

  /// <summary>Field number for the "age" field.</summary>
  public const int AgeFieldNumber = 3;
  private int age_;
  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int Age {
    get { return age_; }
    set {
      age_ = value;
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override bool Equals(object other) {
    return Equals(other as Person);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public bool Equals(Person other) {
    if (ReferenceEquals(other, null)) {
      return false;
    }
    if (ReferenceEquals(other, this)) {
      return true;
    }
    if (FirstName != other.FirstName) return false;
    if (LastName != other.LastName) return false;
    if (Age != other.Age) return false;
    return Equals(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override int GetHashCode() {
    int hash = 1;
    if (FirstName.Length != 0) hash ^= FirstName.GetHashCode();
    if (LastName.Length != 0) hash ^= LastName.GetHashCode();
    if (Age != 0) hash ^= Age.GetHashCode();
    if (_unknownFields != null) {
      hash ^= _unknownFields.GetHashCode();
    }
    return hash;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public override string ToString() {
    return pb::JsonFormatter.ToDiagnosticString(this);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void WriteTo(pb::CodedOutputStream output) {
    if (FirstName.Length != 0) {
      output.WriteRawTag(10);
      output.WriteString(FirstName);
    }
    if (LastName.Length != 0) {
      output.WriteRawTag(18);
      output.WriteString(LastName);
    }
    if (Age != 0) {
      output.WriteRawTag(24);
      output.WriteInt32(Age);
    }
    if (_unknownFields != null) {
      _unknownFields.WriteTo(output);
    }
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public int CalculateSize() {
    int size = 0;
    if (FirstName.Length != 0) {
      size += 1 + pb::CodedOutputStream.ComputeStringSize(FirstName);
    }
    if (LastName.Length != 0) {
      size += 1 + pb::CodedOutputStream.ComputeStringSize(LastName);
    }
    if (Age != 0) {
      size += 1 + pb::CodedOutputStream.ComputeInt32Size(Age);
    }
    if (_unknownFields != null) {
      size += _unknownFields.CalculateSize();
    }
    return size;
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(Person other) {
    if (other == null) {
      return;
    }
    if (other.FirstName.Length != 0) {
      FirstName = other.FirstName;
    }
    if (other.LastName.Length != 0) {
      LastName = other.LastName;
    }
    if (other.Age != 0) {
      Age = other.Age;
    }
    _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
  }

  [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
  public void MergeFrom(pb::CodedInputStream input) {
    uint tag;
    while ((tag = input.ReadTag()) != 0) {
      switch(tag) {
        default:
          _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
          break;
        case 10: {
          FirstName = input.ReadString();
          break;
        }
        case 18: {
          LastName = input.ReadString();
          break;
        }
        case 24: {
          Age = input.ReadInt32();
          break;
        }
      }
    }
  }

}

#endregion


#endregion Designer generated code
