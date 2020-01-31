#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    int n = 0;
    while (t--)
    {
        int num;
        cin >> num;
        if (is_prime(num))
        {
            n++;
        }
    }
    cout << n;
    return 0;
}