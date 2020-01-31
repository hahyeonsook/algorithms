#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    stack<char> sl, sr;
    int t;

    cin >> str;

    for (char ch : str)
    {
        sl.push(ch);
    }

    cin >> t;

    while (t--)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (!sl.empty())
            {
                sr.push(sl.top());
                sl.pop();
            }
        }
        if (cmd == 'D')
        {
            if (!sr.empty())
            {
                sl.push(sr.top());
                sr.pop();
            }
        }
        if (cmd == 'B')
        {
            if (!sl.empty())
                sl.pop();
        }
        if (cmd == 'P')
        {
            char p;
            cin >> p;
            sl.push(p);
        }
    }

    while (!sl.empty())
    {
        sr.push(sl.top());
        sl.pop();
    }

    while (!sr.empty())
    {
        cout << sr.top();
        sr.pop();
    }

    return 0;
}