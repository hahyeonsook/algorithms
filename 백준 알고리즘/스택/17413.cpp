#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    getline(cin, str);
    str += '\n';

    bool t = false;
    stack<char> s;

    for (char ch : str)
    {
        if (t)
        {
            cout << ch;
            if (ch == '>')
                t = false;
        }
        else
        {
            if (ch == ' ' || ch == '\n' || ch == '<')
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                if (ch == '<')
                {
                    cout << ch;
                    t = true;
                }
                else
                    cout << ' ';
            }
            else
                s.push(ch);
        }
    }
    cout << '\n';

    return 0;
}
