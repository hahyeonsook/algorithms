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
		distance = y-x; //�Ÿ� ���ϱ�
		n = 2; s = 2;//�̵� Ƚ��, �Ÿ� �ִ� �� �ʱ�ȭ 
		while(distance > s) {
			n++;
			s = ceil((double)n/2);
			if(n%2 != 0) s = s*s;
			else s = s*s+s;
		} 
		printf("%d\n", n);
	}
}
//n*n�Ҷ�, �����÷ο찡 �߻� double�� ��ġ�� ���� 0 2147483647 �ذ�� �ٵ� �� ��Ÿ�� ���� ��! ���K �ÓP�� 
//�ù� �̹����� �ð� �ʰ��� ������ ��¥! �ð��ʰ��� �ɸ��� ������ *�� �ʹ� ���� �ؼ� �׷��� �������� 
/*
			(n%2 != 0)? (s = s^2): (s = s*(s+1));
			printf("s: %d / s^2: %d, n: %d / n%%2: %d\n", s, s^2, n, n%2);
			*/
