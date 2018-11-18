from person_pb2 import Person

person = Person()
with open('in.bin','rb') as f:
    data = f.read()
    person.ParseFromString(data)

