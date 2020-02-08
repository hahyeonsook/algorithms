#include <iostream>
#include <stack>
#include <string>
using namespace std;
double op[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string cmd;
    cin >> n;
    cin >> cmd;

    for (int i = 0; i < n; i++)
        cin >> op[i];

    stack<double> s;
    for (char ch : cmd)
    {
        if (isalpha(ch))
        {
            s.push(op[ch - 65]);
        }
        else
        {
            double a, b;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();

            if (ch == '+')
                s.push(a + b);
            if (ch == '-')
                s.push(a - b);
            if (ch == '*')
                s.push(a * b);
            if (ch == '/')
                s.push(a / b);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
    return 0;
}