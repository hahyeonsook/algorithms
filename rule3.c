#include <stdio.h>
//ÆÐ½º 
int main(){
	int n, i=0, sum=0;
	scanf("%d", &n);
	while(sum< n) {
		sum += i;
		++i;
		printf("i:%d, sum:%d\n", i, sum);
	}
	if(i%2 != 0)
		printf("%d/%d", i, n-sum+i);
	else
		printf("%d/%d", n-sum+i, i);
}
