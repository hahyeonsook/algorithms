#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned int n;
    int b;
    cin >> n >> b;
    stack<int> s;
    while (n > 0)
    {
        int tmp;
        tmp = n % b;
        s.push(tmp);
        n /= b;
    }

    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        if (tmp >= 10)
        {
            tmp += 55;
            cout << (char)tmp;
        }
        else
        {
            cout << tmp;
        }
    }

    return 0;
}
//1,000,000,000