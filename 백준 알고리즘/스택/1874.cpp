#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<int> s;
    int n;
    string ans;

    cin >> n;

    int m = 0;
    while (n--)
    {
        int x;
        cin >> x;

        if (x > m)
        {
            while (x > m)
            {
                s.push(++m);
                ans += "+\n";
            }
            s.pop();
            ans += "-\n";
        }
        else
        {
            if (s.top() == x)
            {
                s.pop();
                ans += "-\n";
            }
        }
    }
    if (!s.empty())
        cout << "NO";
    else
        cout << ans;

    return 0;
}