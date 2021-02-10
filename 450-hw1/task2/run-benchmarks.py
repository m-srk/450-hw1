#!/usr/local/bin/python3

import os
import sys

samples = [1, 2, 4, 6, 8]
prod = 25000000
i = 10
C = 1
N_vals = []

while i < 10000001:
  for j in samples:
    N = i*j
    R = prod/N + 10
    N_vals.append(N)
    teststr = "./%s %d %d" % (str(sys.argv[1]), N, R)
    cmdcode = os.system(teststr)
    C = C+1
  i = i*10

print("")
for n in N_vals:
  print(n)
