import os
import numpy as np

def read_file(name_file):
  matrix = []
  for eachLine in open(name_file,'rt'):
    matrix.append([int(eachRow) for eachRow in eachLine.split()])
  matrix.pop(0)
  matrix = np.array(matrix)
  return matrix


A = read_file('D:\\Matrix_A_1000.txt')
B = read_file('D:\\Matrix_B_1000.txt')

С_python = np.dot(A,B)

C = read_file('matrix_C.txt')

print((C == С_python).all())
     
