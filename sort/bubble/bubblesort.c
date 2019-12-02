#include <stdio.h>
#include <stdlib.h>

#define CNT 20

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void printArray(int arr[], int cnt) {
	int i;
	for(i=0; i<cnt; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
  int i, j;
  int data[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int data2[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int temp = 0;

  printf("[1]Random Data: ");
  printArray(data, sizeof(data)/sizeof(int));

  for(i=0; i<CNT-1; i++) {
    for(j=0; j<CNT-1-i; j++) {
      if(data[j] > data[j+1]) {
        temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
  }

  printf("[1]Sorted Data: ");
  printArray(data, sizeof(data)/sizeof(int));

  printf("\n\n");
  temp = 0;

  printf("[2]Random Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));

  for(i=0; i < CNT; i++) {
    for(j=0; j<CNT-1-i; j++) {
      if(data2[j] > data2[j+1]) {
        swap(data2, j, j+1);
      }
    }
  }

  printf("[2]Sorted Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));

  return 0;

}
