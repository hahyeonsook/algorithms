#include <stdio.h>

#define CNT 20

void printArray(int arr[], int cnt)
{
  for(int i=0; i<cnt; i++) {

    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int data1[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int data2[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int temp = 0;

  printf("Random Data: ");
  printArray(data1, sizeof(data1)/sizeof(int));

  int indexMin = 0;
  for(int i=0; i<CNT-1; i++) {
    indexMin = i;
    for (int j=i+1; j<CNT; j++) {
      if(data1[indexMin]>data1[j]) {
        indexMin = j;
      }
    }
    temp = data1[indexMin];
    data1[indexMin] = data1[i];
    data1[i] = temp;
  }

  printf("Sorted Data: ");
  printArray(data1, sizeof(data1)/sizeof(int));

  printf("Random Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));

  int indexMax = 0;
  for(int i=0; i<CNT-1; i++) {
    indexMax = i;
    for (int j=i+1; j<CNT; j++) {
      if(data2[indexMax]<data2[j]) {
        indexMax = j;
      }
    }
    temp = data2[indexMax];
    data2[indexMax] = data2[i];
    data2[i] = temp;
  }

  printf("Sorted Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));

  return 0;
}
