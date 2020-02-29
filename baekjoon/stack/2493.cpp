#include <iostream>
#include <string>
using namespace std;
int top[500001] = {
    0,
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string ans = " ";
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int tmp;
        cin >> tmp;

        if (i == 0)
            cout << 0 << ' ';
        else
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (top[j] >= tmp)
                {
                    cout << j + 1 << ' ';
                    break;
                }
                else if (j == 0)
                    cout << 0 << ' ';
            }
        }
        top[i] = tmp;
    }
    cout << '\n';
}

/**
 * 1. 시간초과  -> string ans에 답을 붙인 후 cout을 한번만 하는 방식으로 바꾸자 틀렸습니다.로 나옴.
 * 2. 반례 6 4 5 2 5 1 > 0 1 1 3 3 5(correct), 0 1 1 3 1 5(wrong), 탑의 크기가 같을 때도 수신할 수 있는 경우를 빼먹음.
 * 3. 시간초과
 **/