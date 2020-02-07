#include <iostream>
using namespace std;
int d[12];
int cal(int n)
{
    if (d[n] > 0)
        return d[n];
    d[n] = cal(n - 1) + cal(n - 2) + cal(n - 3);
    return d[n];
}
int main()
{
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << cal(n) << '\n';
    }
    return 0;
}