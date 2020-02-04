#include <iostream>
#include <string>
using namespace std;
string eight[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
int main()
{
    string s;
    cin >> s;
    if (s.length() == 1 && s[0] - '0' == 0)
        cout << "0";

    for (int i = 0; i < s.length(); i++)
    {
        int n = s[i] - '0';
        if (i == 0 && n < 4)
        {
            if (n == 0)
                continue;
            else if (n == 1)
                cout << "1";
            else if (n == 2)
                cout << "10";
            else if (n == 3)
                cout << "11";
        }
        else
            cout << eight[n];
    }
    cout << '\n';
    return 0;
}

/*1차. 출력 초과가 뜸
https://www.acmicpc.net/help/judge
틀리거나 출력 초과가 나오는데..음.. 반례를 찾아봐야하나
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int num = s[i] - '0';
        if (num - 4 >= 0)
        {
            cout << 1;
            num -= 4;
        }
        else if (i != 0)
            cout << 0;
        if (num - 2 >= 0)
        {
            cout << 1;
            num -= 2;
        }
        else if (i != 0)
            cout << 0;
        if (num - 1 >= 0)
        {
            cout << 1;
            num -= 1;
        }
        else
            cout << 0;
    }
    cout << '\n';
    return 0;
}

글로벌 변수로 해결할 수 있는건 해결하기. 스탬프화할 수 있는건 찍어놓기
*/