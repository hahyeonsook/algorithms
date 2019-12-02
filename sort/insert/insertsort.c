#include <stdio.h>

#define CNT 20
void cleanBuf(void) {
	while(getchar()!='\n');
}

void printArray(int arr[], int cnt)
{
  int i;
  for(i=0; i<cnt; i++) {

    printf("%d ", arr[i]);
  }
  printf("\n");
  
}

int main()
{
  int i, j;
  int data1[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int data2[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int data3[CNT] = {5, 15, 7, 20, 1, 4, 10, 2, 8, 11, 9, 6, 13, 18, 3, 16, 12, 14, 17, 19};
  int temp = 0;

  printf("[1]Random Data: ");
  printArray(data1, sizeof(data1)/sizeof(int));

  int indexMin = 0;
  for(i=0; i<CNT-1; i++) {
    indexMin = i;
    for (j=i+1; j<CNT; j++) {
      if(data1[indexMin]>data1[j]) {
        indexMin = j;
      }
    }
    temp = data1[indexMin];
    data1[indexMin] = data1[i];
    data1[i] = temp;
  }

  printf("[1]Sorted Data: ");
  printArray(data1, sizeof(data1)/sizeof(int));
  
  printf("[3]Random Data: ");
  printArray(data3, sizeof(data3)/sizeof(int));

  for(i = 0; i < CNT; i++) {
  	for(j = i + 1; j > i; j--) {
  		if(data3[j] < data3[j - 1]) {
  			temp = data3[j - 1];
  			data3[j - 1] = data3[j];
  			data3[j] = temp;
		}
	}
  }

  printf("[3]Sorted Data: ");
  printArray(data3, sizeof(data3)/sizeof(int));

  printf("[2]Random Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));

  for(i = 0; i < CNT - 1; i++) {
  	j = i;
  	while(data2[j] > data2[j + 1]) {
  		temp = data2[j];
  		data2[j] = data2[j + 1];
  		data2[j + 1] = temp;
  		j--;
	}
  }

  printf("[2]Sorted Data: ");
  printArray(data2, sizeof(data2)/sizeof(int));
  
  
  

  return 0;
}
