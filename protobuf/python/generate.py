from messages_v1_pb2 import Person, Group

group = Group()

person = Person()
for i in range(2):
    person = group.individuals.add()
    person.firstName = "John"
    person.lastName = "Doe"
    person.age = i


serialized = group.SerializeToString()

import sys
sys.stdout.buffer.write(serialized)

