#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    char op[100] = {
        0,
    };
    int i = 0;

    cin >> op;
    while (op[i] != 0)
    {
        if (isalpha(op[i]))
            cout << op[i];
        else if (s.empty() || op[i] == '*' || op[i] == '/' || op[i] == '(')
        {
            s.push(op[i]);
        }
        else if (op[i] == ')')
        {
            while (s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            cout << s.top();
            s.pop();
        }
        else if (op[i] == '+' || op[i] == '-')
        {
            while (!s.empty())
            {
                cout << "not Empty" << endl;
                cout << s.top();
                s.pop();
            }
            s.push(op[i]);
        }
        i++;
    }

    while (!s.empty()) //true이면 실행됨
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}