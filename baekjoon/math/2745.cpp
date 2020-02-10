#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string n;
    unsigned int ans = 0;
    int b;
    cin >> n >> b;

    for (int i = 0, m = n.length(); i < m; i++)
    {
        int tmp = n[i];
        if (tmp >= 65 && tmp <= 90)
            tmp -= 55;
        else if (tmp >= 48 && tmp <= 57)
            tmp -= 48;
        tmp = tmp * pow(b, (m - i - 1));
        ans += tmp;
    }
    if (b < 2 || b == 10)
        cout << n;
    else
        cout << ans;
    return 0;
}

/**
 * 10진법만 입력하면 세번째 수의 숫자가 적게 나온다. 왜그런건지는 모르겟다. 
 **/