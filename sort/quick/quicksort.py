import random

def leftSort(arr, start, end):
    pivot = arr[start]
    left = start+1
    right = end
    print(pivot, left, right)
    while left<=right:
        while arr[left]<pivot:
            left=left+1
        while arr[right]>pivot:
            right=right+1

        if left<=right:
            arr[left], arr[right]=arr[right], arr[left]

    if(start<end):
        arr[start], arr[right]

        leftSort(arr, start, right-1)
        leftSort(arr, right+1, end)

if __name__ == "__main__":

    arr=[i for i in range(100)]
    random.shuffle(arr)

    print("Random Data\n{}\n".format(arr))
    leftSort(arr, 0, len(arr)-1)
    print("Sorted Data\n{}\n".format(arr))

