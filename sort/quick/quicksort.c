//https://blockdmask.tistory.com/177
#include <stdio.h>

#define CNT 7

void swap(int* arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void printArray(int* arr, int cnt)
{
  for(int i=0; i<cnt; i++) {

    printf("%d ", arr[i]);
  }
  printf("\n");
}

void leftQuickSort(int* arr, int start, int end)
{
  int pivot = arr[start];
  int left = start+1;
  int right = end;

  while(left <= right) {

    while(arr[left] < pivot) { left++; }
    while(arr[right] > pivot) { right--; }

    if(left <= right) { swap(arr, left, right); }
  }

  if(start < end) {
    swap(arr, start, right);

    leftQuickSort(arr, start, right-1);
    leftQuickSort(arr, right+1, end);
  }

  return ;
}

void rightQuickSort(int* arr, int start, int end)
{
  int pivot = arr[end];
  int left = start;
  int right = end-1;

  while (left <= right)
  {
    while(arr[left] < pivot) { left++; }
    while(arr[right] > pivot) { right--; }

    if(left >= right) { swap(arr, left, right); }

    if(start < end) {
      swap(arr, left, end);

      rightQuickSort(arr, start, left-1);
      rightQuickSort(arr, left+1, end);
    }

    return;
  }
  
}

int main()
{
  //int arr1[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  //int arr2[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};

  int arr1[CNT] = {5, 3, 7, 6, 2, 1, 4};
  int arr2[CNT] = {5, 3, 7, 6, 2, 1, 4};

  printf("Random Data: ");
  printArray(arr1, sizeof(arr1)/sizeof(int));

  leftQuickSort(arr1, 0, CNT-1);

  printf("Sorted Data: ");
  printArray(arr1, sizeof(arr1)/sizeof(int));

  printf("Random Data: ");
  printArray(arr2, sizeof(arr2)/sizeof(int));

  rightQuickSort(arr2, 0, CNT-1);

  printf("Sorted Data: ");
  printArray(arr2, sizeof(arr2)/sizeof(int));

  return 0;
}