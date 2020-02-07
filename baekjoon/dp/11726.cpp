#include <iostream>
using namespace std;
long long d[1001];
long cal(int n)
{

    d[1] = 1;
    d[2] = 2;
    if (d[n] > 0)
        return d[n];
    d[n] = (cal(n - 1) + cal(n - 2)) % 10007;
    return d[n];
}
int main()
{
    int n;
    cin >> n;
    cout << cal(n) << '\n';
    return 0;
}

/*
1000까지 가면 long long의 범위를 넘는다.
아니.....후....10007을 1007로 계산하고 잇었음...
*/