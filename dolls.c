#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanBuf(void) {
	while(getchar()!='\n');
}

int main() {
	int T, n, m, *kd, i, *an;
	char str[1024];
	scanf("%d", &T); cleanBuf();
	if(T<1||T>50) return -1; //변수 범위 검사 
	while(T--){
		scanf("%[^\n]s", str); cleanBuf();
		n = atoi(strtok(str, " "));
		m = atoi(strtok(NULL, " "));
		if(n<1||n>100000) return -1; //변수 범위 검사 
		kd = malloc(sizeof(int)*n);
		an = malloc(sizeof(int)*n);
		for(i=0;i<n;i++) an[i]=0;
		
		scanf("%[^\n]s", str); cleanBuf();
		kd[0] = atoi(strtok(str, " "));

		for(i=1;i<n;i++){
			kd[i] = atoi(strtok(NULL, " "));
		}

		while(m>0){
			for(i=0;i<n;i++){
				if(kd[i]!=0 && m>0){
					an[i]++; kd[i]--;
					m--;
					printf("[%d] m:%d kd[%d]:%d an[%d]:%d\n", T, m, i, kd[i], i, an[i]);
				}
			}
		}
		printf("%d %d %d\n", an[0], an[1], an[2]);
		free(kd); free(an);
	}
}
