/*
* 0번부터 차례로 번호 매겨진 n 개의 원소 중 네 개를 고르는 모든 경우를 출력하라.
* 1. 몇 분에 문제를 이해했나?
* 2. 몇 분동안 풀이를 생각했나?
* 3. 몇 분동안 코딩했나?
* 4. 몇 분동안 디버깅했나?
*/
#include <iostream>
#include <vector>

using namespace std;

/* 재귀 호출로 변경해보라.
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                for (int l = k + 1; l < n; ++l)
                    cout << i << "" << j << "" << k << "" << l << endl;

    return 0;
}
*/

void printPicked(vector<int> &picked)
{
    while (!picked.empty())
    {
        cout << picked.pop_back() << end;
    }
}

/*
* n: 전체 원소의 수
* picked: 지금까지 고른 원소들의 번호
* toPick: 더 고를 원소의 수
* 일 때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
*/
void pick(int n, vector<int> &picked, int toPick)
{
    //기저 사례, 더 고를 원소가 없을 때 고른 원소들을 출력한다.
    if (toPick == 0)
    {
        printPicked(picked);
        return;
    }

    //고를 수 있는 가장 작은 번호를 계산한다.
    int smallest = picked.empty() ? 0 : picked.back() + 1;

    //이 단계에서 원소 하나를 고른다.
    for (int next = smallest; next < n; ++next)
    {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main()
{
    int n = 0;
    vector<int> picked;
    int toPick = 0;

    cin >> n;
    toPick = n;

    pick(n, picked, toPick);
    return 0;
}