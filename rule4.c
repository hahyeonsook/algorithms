#include <stdio.h>
#include <math.h>
void cleanBuf(void) {
	while(getchar()!='\n');
}
int main() {
	int cases, n;
	long long s, x, y, distance;
	
	scanf("%d", &cases); cleanBuf();
	while(cases--) {
		scanf("%lld %lld", &x, &y); cleanBuf();
		distance = y-x; //거리 구하기
		n = 2; s = 2;//이동 횟수, 거리 최대 값 초기화 
		while(distance > s) {
			n++;
			s = ceil((double)n/2);
			if(n%2 != 0) s = s*s;
			else s = s*s+s;
		} 
		printf("%d\n", n);
	}
}
//n*n할때, 오버플로우가 발생 double로 고치고 나니 0 2147483647 해결됨 근데 또 런타임 에러 뜸! 하핳 시밣ㅎ 
//시발 이번에는 시간 초과야 좆같네 진짜! 시간초과가 걸리는 이유가 *을 너무 많이 해서 그런거 ㅅ같은데 
/*
			(n%2 != 0)? (s = s^2): (s = s*(s+1));
			printf("s: %d / s^2: %d, n: %d / n%%2: %d\n", s, s^2, n, n%2);
			*/
