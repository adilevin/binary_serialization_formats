protoc --python_out=./python ./proto/messages_v1.proto
protoc --python_out=./python ./proto/messages_v2.proto
protoc --cpp_out=./cpp ./proto/messages_v1.proto
protoc --cpp_out=./cpp ./proto/messages_v2.proto
protoc --cpp_out=./cpp ./proto/person.proto
protoc --java_out=./java ./proto/person.proto
protoc --csharp_out=./csharp ./proto/person.proto
