//Eublid's algorithm, 최대공약수 찾기
#include <stdio.h>
#include <dos.h>
#include "timer.h"

/*뺄셈 이용*/
int gcd_minus(int u, int v)
{
    int t;

    while(u)
    {
        if(u < v)/*u<v이면, v와 u를 교환*/
        {
            t = u;
            u = v;
            v = t;
        }

        u = u-v; /*u에 u-v 값을 저장*/
    }

    return v; /*u가 0이면 v는 최대공약수, u가 0이 아니면 while*/
}

/*나머지 연산 이용*/
int gcd_modulus(int u, int v)
{
    int t;
    while(v)/*%v하는 v(계산 값)가 0이 아니면 루프, 0이면 %값 u 리턴*/
    {   /*280%30 = 10*/
        t = u%v; /*t가 module 값, 나머지 10*/
        u = v; /*v(operand2, 30)를 u(operand1, 280)에 대입, 다음 operand1*/
        v = t; /*v(operand2, 30)에 %값 10을 대입, 다음 계산 준비*/
    }

    return u;
}

/*재귀 호출 이용*/
int gcd_recursion(int u, int v)
{
    if(v==0)
        return u;
    else
        return gcd_recursion(v, u%v);
}

#define LOOP 10000


void main(void)
{
    int u, v, gcd;
    long t1, t2; //시간을 저장할 변수
    int i;

    puts("\n EUCLID1: Get GCD of two positive integer"
         "\n          Input 0 to end program");

    while(1)
    {
        puts("\n\n Input tow positive integer -> ");
        scanf("%d %d", &u, &v);
        if(u < 0 || v < 0) /*음수의 입력은 무효로 한다.*/
            continue;
        if(u == 0 || v == 0) /*0이 입력되면 종료*/
            break;

        t1=get_tick();
        for(i=0; i<LOOP;i++)
            gcd = gcd_minus(u, v);
        t2=get_tick();
        printf("\nMinus methods: GCD of %d and %d is %d in %ld ticks.", u, v, gcd, diff_tick(t1, t2));

        t1=get_tick();
        for(i=0; i<LOOP;i++)
            gcd = gcd_modulus(u, v);
        t2=get_tick();
        printf("\nMonulus methods: GCD of %d and %d is %d in %ld ticks.", u, v, gcd, diff_thick(t1, t2));

        t1=get_tick();
        for(i=0; i<LOOP;i++)
            gcd = gcd_recursion(u, v);
        t2=get_tick();
        printf("\nRecursion methods: GCD of %d and %d is %d in %ld ticks.", u, v, gcd, diff_thick(t1, t2));

    }
}
