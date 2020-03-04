#include <iostream>
#include <algorithm>
using namespace std;
bool c[10];
int a[10], arr[10]; // 1 4 8 10 15 20
int n, ans = 0;
int f()
{
    int tmp = 0;
    if (n % 2 != 0)
        tmp += (a[n] >= 0) ? a[n] : a[n] * (-1);
    for (int i = 0; i < n; i += 2)
    {
        int t = a[i] - a[i + 1];
        tmp += (t >= 0) ? t : t * (-1);
    }
    cout << tmp << '\n';
    return tmp;
}
void g(int index)
{
    if (index == n)
    {
        ans = (f() > ans) ? f() : ans;
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i] == true)
            continue;
        a[index] = arr[i];
        c[i] = true;
        g(index + 1);
        c[i] = false;
    }
    return;
}
void g()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    g(0);
    cout << ans << '\n';
    return 0;
}