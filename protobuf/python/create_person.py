from person_pb2 import Person

person = Person()

person.firstName = "John"
person.lastName = "Doe"
person.age = 24

serialized = person.SerializeToString()

with open('out.bin','wb') as f:
    f.write(serialized)

