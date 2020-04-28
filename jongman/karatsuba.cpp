#include <iostream>
#include <vector>
#include <algorithm>
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

// a += b*(10^k);
void addTo(vector<int> &a, const vector<int> &b, int k);
//a -= b; a>=b를 가정.
void subFrom(vector<int> &a, const vector<int> &b);
vector<int> karasuba(const vector<int> &a, const vector<int> &b)
{
    int an = a.size(), bn = b.size();
    //a 가 b 보다 짧을 경우 둘을 바꿈.
    if (an < bn)
        return karasuba(b, a);
    //기저 사례: a나 b가 비어 있는 경우.
    if (an == 0 || bn == 0)
        return vector<int>();
    //기저 사례: a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경.
    if (an <= 50)
        return multiply(a, b);
    int half = an / 2;
    //a와 b를 half 자리와 나머지로 분리.
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    //z2 = a1 * b1
    vector<int> z2 = karasuba(a1, b1);
    //z0 = a0 * b0
    vector<int> z0 = karasuba(a0, b0);
    //a0 = a0 + a1; b0 = a0 + b1;
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    //z1 = (a0 * b1) - z0 - z2;
    vector<int> z1 = karasuba(a0, b1);
    subFrom(z1, z0);
    subFrom(z1, z2);
    //ret = z0 + z1 * 10^half + z2 * 10^(half*2)
    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}
int main()
{
    return 0;
}