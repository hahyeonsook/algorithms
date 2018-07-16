//Eublid's algorithm, 최대공약수 찾기
#include <stdio.h>

int get_gcd(int u, int v)
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

int gcd_moduls(int u, int v)
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

int gcd_recursion(int u, int v)
{
    if(v==0)
        return u;
    else
        return gcd_recursion(v, u%v);
}

void main(void)
{
    int u, v;

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
        printf("\n    GCD of %d and %d is %d.", u, v, get_gcd(u, v));
        printf("\n    GCD of %d and %d is %d.", u, v, gcd_moduls(u, v));
        printf("\n    GCD of %d and %d is %d.", u, v, gcd_recursion(u, v));

    }
}
