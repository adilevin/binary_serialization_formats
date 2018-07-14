from messages_v2_pb2 import Group
from google.protobuf.json_format import MessageToJson

import sys
data = sys.stdin.buffer.read()

group = Group()
group.ParseFromString(data)

j = MessageToJson(group, including_default_value_fields=True)
print(j)