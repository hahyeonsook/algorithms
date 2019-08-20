// 매번 연속된 두 개 인덱스를 비교하여 (오름차순일 경우) 큰 값을 뒤로 넘겨 정렬
#include <stdio.h>
#include <stdlib.h>

#define CNT 20

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void printArray(int arr[], int cnt)
{
  for(int i=0; i<cnt; i++) {

    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int data[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int data2[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int temp = 0;

  printf("Random Data: ");
  printArray(data, sizeof(data)/sizeof(int));

  for(int i=0; i<CNT-1; i++) {
    for(int j=0; j<CNT-1-i; j++) {
      if(data[j]>data[j+1]) {
        temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }

  printf("Sorted Data: ");
  printArray(data, sizeof(data)/sizeof(int));

  printf("\n\n");
  temp = 0;

  printf("Random Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));

  for(int i=0; i<CNT-1; i++) {
    for(int j=0; j<CNT-1-i; j++) {
      if(data2[j]<data2[j+1]) {
        swap(data2, j, j+1);
      }
    }
  }

  printf("Sorted Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));

  return 0;

}
