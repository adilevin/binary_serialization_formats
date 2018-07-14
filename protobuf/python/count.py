from messages_v2_pb2 import Group

import sys
data = sys.stdin.buffer.read()

group = Group()
group.ParseFromString(data)

print(len(group.individuals))