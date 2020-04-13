#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int multiples[19];
string rules = "124";
void init()
{
    multiples[0] = 1;
    for (int i = 1, n = 3; i < 19; i += 1, n *= 3)
        multiples[i] = n;
}
string solution(int n)
{
    string answer = "";
    int digits = 0; //자리수는 최대 18 + 1

    // 자리수를 알아냄.
    for (int i = 3, tmp = n; tmp > 0; i *= 3)
    {
        tmp -= i;
        digits += 1;
    }
    // 자리를 계산함
    for (int i = 0, d = digits - 1; i < digits; i++)
    {
        for (int j = 3; j > 0; j--)
        {
            if ((n - multiples[digits - i - 1] * j) >= 0)
            {
                n -= multiples[digits - i - 1] * j;
                answer += rules[j - 1];
                break;
            }
        }
    }
    return answer;
}

int main()
{
    init();
    for (int i = 1; i <= 20; i++)
        cout << "[" << i << "]" << solution(i) << '\n';
    return 0;
}

// 3의 제곱수에서 초기화됨.