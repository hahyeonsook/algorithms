#include <iostream>
using namespace std;
long long d[1001];
long cal(int n)
{
    if (d[n] > 0)
        return d[n];
    d[n] = (cal(n - 1) + cal(n - 2) * 2) % 10007;
    return d[n];
}
int main()
{
    d[1] = 1;
    d[2] = 3;
    int n;
    cin >> n;
    cout << cal(n) << '\n';
    return 0;
}