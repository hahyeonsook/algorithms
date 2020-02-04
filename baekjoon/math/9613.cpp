#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long g = 0; // sum이 int 값이면 부족함.
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++)
            cin >> num[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    g += gcd(num[i], num[j]);
            }
        }
        cout << g / 2 << '\n';
    }
    return 0;
}