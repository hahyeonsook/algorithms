#include <iostream>
#include <stack>
#include <string>
using namespace std;
int vps(string ps)
{
    stack<char> s;
    int ans = 0;
    for (char ch : ps)
    {
        if (ch == '(' || '[')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                s.push('2');
            }
            else if (s.top() == '[')
            {
                s.pop();
                s.push('3');
            }
            else if ()
        }
    }
}
int main()
{
    string ps;
    cin >> ps;

    return 0;
}