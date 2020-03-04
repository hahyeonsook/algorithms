//https://www.acmicpc.net/problem/15650
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g(1, 0);
    return 0;
}

#include <iostream>
using namespace std;
int a[10];
void go(int index, int selected, int n, int m)
{
    if (selected == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (index > n)
        return;
    a[selected] = index;
    go(index + 1, selected + 1, n, m);
    a[selected] = 0;
    go(index + 1, selected, n, m);
}
int main()
{
    int n, m;
    cin >> n >> m;
    go(1, 0, n, m);
    return 0;
}

/**
#include <iostream>
using namespace std;
int a[10], n, m;
//void로 바꾸니 런타임 에러가 고쳐짐!!!! 원인 찾아볼 것
void g(int index, int selected)
{
    if (selected == m)
    {
        for (int i = 0; i < m; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return 0;
    }
    if (index > n)
        return 0;
    //선택하는 경우
    a[selected] = index;
    g(index + 1, selected + 1);
    //선택하지 않는 경우
    a[selected] = 0; //0으로 초기화하지 않으면 런타임 에러가 난다.
    g(index + 1, selected);
}
* n, m을 전역변수로 선언했더니 런타임 에러가 난다.
**/

/**
#include <iostream>
using namespace std;
int index, a[8], n, m;
int g(int index, int start)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    for (int i = start; i <= n; i++)
    {
        a[index] = i;
        g(index + 1, i + 1);
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g(0, 1);
    return 0;
}
**/

/**
//https://yabmoons.tistory.com/100?category=838490
#include <iostream>
#include <vector>
using namespace std;
int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
bool s[8] = {
    false,
};
vector<int> per;
int n, m;
void out()
{
    for (int i = 0; i < per.size(); i++)
    {
        cout << per[i] << ' ';
    }
    cout << '\n';
}
void dfs(int cnt)
{
    if (cnt == m)
        out();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == true)
            continue;
        if (cnt == 0 || per.back() < arr[i])
        {
            s[i] = true;
            per.push_back(arr[i]);
            dfs(cnt + 1);
            per.pop_back();
            s[i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    dfs(0);
    return 0;
}
**/