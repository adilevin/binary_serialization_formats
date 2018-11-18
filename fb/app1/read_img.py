import flatbuffers # Prerequisite: pip install flatbuffers 

import sys
sys.path.insert(0, '../my_types/generated/python')

from generated_code.Image import Image

buf = open('img.dat', 'rb').read()
buf = bytearray(buf)
img = Image.GetRootAsImage(buf, 0)

s = """
Width = %d
Height = %d
Pixels = %s
""" % (img.Dim().Width(), img.Dim().Height(), img.PixelsAsNumpy())

print(s)
