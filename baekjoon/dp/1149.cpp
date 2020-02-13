#include <iostream>
using namespace std;
int d[10001][3];
int c[10001][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            d[i][0] = c[i][0];
            d[i][1] = c[i][1];
            d[i][2] = c[i][2];
        }
        else
        {
            d[i][0] = min(d[i - 1][1], d[i - 1][2]) + c[i][0];
            d[i][1] = min(d[i - 1][0], d[i - 1][2]) + c[i][1];
            d[i][2] = min(d[i - 1][0], d[i - 1][1]) + c[i][2];
        }
    }

    cout << min(min(d[n][0], d[n][1]), d[n][2]) << '\n';
    return 0;
}
/**
 * 1. 점화식 정의에서 조건으로 추가된 변수에 대한 정의를 빼먹어서 점화식 정의가 불완전했음.
 * 2. 예외처리 빼먹음
 * 3. 입력에서 i의 범위를 잘못 처리해서 틀림
 * 이 문에 질문코너에서 그리디와 dp의 차이점에 대한 글이 있음.
 **/