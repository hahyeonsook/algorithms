import random

def ascSort(arr):

  for i in range(0, 99):
    indexMin = i
    for j in range(i+1, 100):
      if arr[indexMin]>arr[j]:
        indexMin = j
    arr[indexMin], arr[i] = arr[i], arr[indexMin]

def desSort(arr):

  for i in range(0, 99):
    indexMax = i
    for j in range(i+1, 100):
      if arr[indexMax]<arr[j]:
        indexMax = j
    arr[indexMax], arr[i] = arr[i], arr[indexMax]


if __name__ == "__main__":

  arr=[i for i in range(100)]
  random.shuffle(arr)

  print("Random Data\n{}\n".format(arr))

  ascSort(arr)
  print("ASCed Data\n{}\n".format(arr))

  desSort(arr)
  print("DESed Data\n{}\n".format(arr))

