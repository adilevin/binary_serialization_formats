
class Person : public ::google::protobuf::Message {
  
  public:
  
    Person();
    virtual ~Person();
    Person(const Person& from);
    inline Person& operator=(const Person& from)
  
    void set_firstname(const ::std::string& value);
    void set_firstname(::std::string&& value);
    void set_firstname(const char* value);
    void set_firstname(const char* value, size_t size);
    ::std::string* mutable_firstname();
    ::std::string* release_firstname();  
    void set_allocated_firstname(::std::string* firstname);
    void clear_firstname();
    const ::std::string& firstname() const;
  
    ...
    
    void CopyFrom(const Person& from);
    void MergeFrom(const Person& from);
    void Clear() final;
    bool IsInitialized() const final;  
  }
  
  
  
  