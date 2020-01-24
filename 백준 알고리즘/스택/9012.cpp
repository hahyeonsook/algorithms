#include <iostream>
#include <string>

using namespace std;

string vps(string str)
{
    int s = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s++;
        else
            s--;
        if (s < 0)
            return "NO";
    }
    if (s == 0)
        return "YES";
    else
        return "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str; //여기서 getline으로 받았을 때 틀렸는데 아마 \n이 같이 들어가서 그런듯

        cout << vps(str) << '\n';
    }
}