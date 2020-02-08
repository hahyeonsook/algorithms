#include <iostream>
#include <string>
using namespace std;
int s[26];
int main()
{
    for (int i = 0; i < 26; i++)
        s[i] = -1;
    string wrd;
    cin >> wrd;
    for (int i = 0; i < wrd.length(); i++)
    {
        s[wrd[i] - 97] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        string tmp = wrd;
        if (s[i] > -1)
            cout << tmp.substr(s[i]) << '\n';
    }
    return 0;
}