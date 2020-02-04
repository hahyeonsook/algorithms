#include <iostream>
#include <vector>
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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x = x - s;
        if (x < 0)
            x = -x;
        a[i] = x;
    }
    int ans = a[0];
    for (int i = 1; i < n; i++)
        ans = gcd(ans, a[i]);
    cout << ans << '\n';
    return 0;
}
// stack을 사용했는데 1000000000가 남동생의 위치로 들어오자 값이 나오지 않고 종료되어버림.
// 아마 stack에 뭐가 안되는듯