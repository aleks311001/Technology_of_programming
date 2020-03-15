import math

file = open("index.h", "w")

wr = "long double PI = " + str(math.pi) + ";"

file.write(wr)
file.close()
