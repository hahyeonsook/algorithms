#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanBuffer(void){ 
	while(getchar()!='\n');
}

int main() {
    int cases, i, pt[4][2];
    char pts[20];
    scanf("%d", &cases); cleanBuffer();
    while(cases--) {
        for(i=0;i<3;i++) {
			fgets(pts, 20, stdin);
            pt[i][0]=atoi(strtok(pts, " "));
            pt[i][1]=atoi(strtok(NULL, " "));
        }
        pt[3][0]=(pt[0][0]==pt[1][0])?pt[2][0]:((pt[0][0]==pt[2][0])?pt[1][0]:pt[0][0]);
        pt[3][1]=(pt[0][1]==pt[1][1])?pt[2][1]:((pt[0][1]==pt[2][1])?pt[1][1]:pt[0][1]);
        printf("%d %d\n", pt[3][0], pt[3][1]);
    }
}

//http://ddoddofather.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EC%9E%85%EB%A0%A5%EB%B2%84%ED%8D%BC%EB%A5%BC-%EB%B9%84%EC%9A%B0%EB%8A%94-%ED%95%A8%EC%88%98
