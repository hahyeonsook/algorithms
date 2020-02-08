#include <iostream>
using namespace std;
int main()
{
    long long a, b, ans = 0;
    for (int i = 0; i < 2; i++)
    {
        cin >> a >> b;
        int j = 1;
        while (j <= b)
            j *= 10;
        ans += a * j + b;
    }
    cout << ans << '\n';
    return 0;
}