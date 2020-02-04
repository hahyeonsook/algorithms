#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if (n % 3 == 1)
    {
        cout << s[0];
    }
    else if (n % 3 == 2)
    {
        cout << (s[0] - '0') * 2 + (s[1] - '0');
    }
    for (int i = n % 3; i < n; i += 3)
    {
        cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
    }
    cout << '\n';
    return 0;
}
/*
* 1차. 시간초과함
    string binary, ans;
    cin >> binary;
    for (int i = binary.size(); i > 0; i -= 3)
    {
        int n = 0;
        for (int j = 0, sq = 1; j < 3; j++, sq *= 2)
        {
            if (binary[i - j - 1] == '1')

                n += sq;
        }
        ans = to_string(n) + ans;
    }
    cout << ans;

    너무 어렵게 생각했다... 간단하게 줄이는 방법을 고심해봐야겟다.
*/