//https://www.acmicpc.net/problem/10973
#include <iostream>
using namespace std;
bool prev_permutation(int *a, int n)
{
    int i = n - 1;
    while (i > 0 && a[i - 1] <= a[i])
        i -= 1;
    if (i <= 0)
        return false;
    int j = n - 1;
    while (a[j] >= a[i - 1])
        j -= 1;
    swap(a[i - 1], a[j]);
    j = n - 1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (prev_permutation(a, n))
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}