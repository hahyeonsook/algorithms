#include <iostream>
using namespace std;
bool c[10001];
int a[10001], t[10001];
int n;
void g(int index)
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == true)
            continue;
        c[i] = true;
        a[index] = i;
        g(index + 1);
        c[i] = false;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]] = true;
    }
    g(4);
    return 0;
}