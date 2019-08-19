import random

def ascSort(arr):

  for i in range(0, 98):
    for j=i+1 in range(0, 99)


if __name__ == "__main__":

  arr=[i for i in range(100)]
  random.shuffle(arr)

  print("Random Data\n{}\n".format(arr))

  ascSort(arr)
  print("ASCed Data\n{}\n".format(arr))

  desSort(arr)
  print("DESed Data\n{}\n".format(arr))

