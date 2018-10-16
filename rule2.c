#include <stdio.h>
int main() {
	int n, i=1, sum=1;
	scanf("%d", &n);
	while(n > sum) {
		sum += i*6;
		++i;
	}
	printf("%d", i);
}
