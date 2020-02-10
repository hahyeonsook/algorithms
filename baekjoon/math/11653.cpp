#include <iostream>
using namespace std;
long long prime[10000001];
bool check[10000001];
int pn = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (check[i] == false)
        {
            prime[pn++] = i;
            for (int j = i + i; j <= n; j += i)
                check[j] = true;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (check[i] == false)
        {
            while (n % i == 0)
            {
                cout << i << '\n';
                n /= i;
            }
        }
    }
    return 0;
}