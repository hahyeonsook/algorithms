#include <iostream>
#include <vector>
using namespace std;
bool check[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> primes;
    for (int i = 2; i <= 1000000; i++)
    {
        if (check[i] == false)
        {
            primes.push_back(i);
            for (int j = i + i; j <= 1000000; j += i)
            {
                check[j] = true;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        if (check[n - 2] == false)
            ans++;
        for (int i = 3; i < n; i += 2)
        {
            if (check[i] == false)
            {
                int x = n - i;
                if (x >= i && check[x] == false)
                    ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}