#include <iostream>
#include <vector>
using namespace std;
//num[]의 자릿수 올림을 처리함.
void normalize(vector<int> &num)
{
    num.push_back(0);
    //자릿수 올림 처리
    for (int i = 0; i < num.size(); ++i)
    { //자릿수가 음수일 때
        if (num[i] < 0)
        {
            //자릿수가 10진수를 넘을 때, /10을 하면 다음 윗 자리로 넘길 수를 구할 수 있음.
            //(|음수|+9)/10 => -1~-10까지 1을 넘겨줌.
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    //숫자의 앞 자리가 0이면 삭제함.
    while (num.size() > 1 && num.back() == 0)
        num.pop_back();
}
//multiply({3, 2, 1}, {6, 5, 4}) = 123 * 456 = 56088 = {8, 8, 0, 6, 5}
vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}
int main()
{
    return 0;
}