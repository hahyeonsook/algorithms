#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    getline(cin, str);

    char p_ch = ' ';
    int s = 0, num = 0;

    for (char ch : str)
    {
        if (ch == '(')
        {
            s++;
            p_ch = ch;
        }
        else
        {
            s--;
            if (p_ch == '(')
            {
                num += s;
            }
            else
                num++;
            p_ch = ')';
        }
    }
    cout << num;

    return 0;
}