import avro.schema
from avro.datafile import DataFileReader, DataFileWriter
from avro.io import DatumReader, DatumWriter

schema = avro.schema.Parse(open("../person.avsc").read())

writer = DataFileWriter(open("persons.avro", "wb"), DatumWriter(), schema)
writer.append({"firstName": "John", "lastName": "Doe", "age": 40})
writer.append({"firstName": "Jane", "lastName": "Doe", "age": 30})
writer.close()

reader = DataFileReader(open("persons.avro", "rb"), DatumReader())
for person in reader:
    print(person)
reader.close()



