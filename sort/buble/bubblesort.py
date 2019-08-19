import random

def ascSort(arr):

  for i in range(0,99):
    for j in range(0, 99-i):
      if arr[j]>arr[j+1]:
        arr[j], arr[j+1] = arr[j+1], arr[j]

def desSort(arr):
  for i in range(0,99):
    for j in range(0, 99-i):
      if arr[j]<arr[j+1]:
        arr[j], arr[j+1] = arr[j+1], arr[j]

if __name__ == "__main__":

  arr=[i for i in range(100)]
  random.shuffle(arr)

  print("Random Data\n{}\n".format(arr))

  ascSort(arr)
  print("ASCed Data\n{}\n".format(arr))

  desSort(arr)
  print("DESed Data\n{}\n".format(arr))
