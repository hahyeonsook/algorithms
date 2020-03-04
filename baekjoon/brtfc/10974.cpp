#include <iostream>
using namespace std;
bool c[8];
int a[8], n;
int g(int index)
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == true)
            continue;
        a[index] = i;
        c[i] = true;
        g(index + 1);
        c[i] = false;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    g(0);
    return 0;
}