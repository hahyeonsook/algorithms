#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
constexpr int int_pow(int b, int e)
{
    return (e == 0) ? 1 : b * int_pow(b, e - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, m;
    cin >> a >> b >> m;

    // A 진법을 10진수로 변환
    unsigned int tob = 0;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        tmp = tmp * int_pow(a, (m - i - 1));
        tob += tmp;
    }
    stack<int> s;
    while (tob > 0)
    {
        int tmp;
        tmp = tob % b;
        s.push(tmp);
        tob /= b;
    }

    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        cout << tmp << ' ';
    }
    return 0;
}