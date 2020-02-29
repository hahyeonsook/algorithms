#include <iostream>
#include <string>
using namespace std;
string vps(string ps)
{
    int n = 0;
    for (char ch : ps)
    {
        if (ch == '(')
            n += 1;
        else if (ch == ')')
            n -= 1;
        if (n < 0)
            return "NO";
        /*
        * n이 음수가 되는지 확인하지 않아서 틀렸는데, 음수가 될 경우 ))))이 (의 개수를 초과하였고, 이 부분을 처리해주지 않으면 뒤에 )의 개수만큼 (이 나오면 0이 되어 맞는 것으로 나오기 때문임.
        */
    }

    if (n == 0)
        return "YES";
    else
        return "NO";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string ps;
        cin >> ps;

        cout << vps(ps) << '\n';
    }
    return 0;
}