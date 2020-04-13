#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> g[1001]; // 그래프 인접리스트 형식으로 나타냄
bool d_check[1001] = {
    false,
};
bool b_check[1001] = {
    false,
};
// 재귀함수로 푼다.
void dfs(int from)
{
    //from의 값으로 dfs를 들어오면, 이 값을 탐색했다는 표시로 d_check의 from 값을 true로 바꿔줌
    d_check[from] = true;
    cout << from << ' ';
    //from의 간선이 비어있지 않다면, 연결된 정점이 있다면
    for (int i = 0, max = g[from].size(); i < max; i++)
    {
        //연결된 정점 중 탐색되지 않은 정점을 검색한다.
        if (!d_check[g[from][i]])
        {
            //탐색되지 않은 to값을 찾으면, dfs로 보낸다.
            dfs(g[from][i]);
        }
    }
}
void bfs(int from)
{
    queue<int> to;
    to.push(from);
    b_check[from] = true;
    cout << from << ' ';
    while (!to.empty())
    {
        from = to.front(); //앞에있는 수를 다음 시작점으로 지정한다.
        to.pop();
        for (int i = 0, max = g[from].size(); i < max; i++)
        {
            if (!b_check[g[from][i]])
            {
                to.push(g[from][i]);
                b_check[g[from][i]] = true;
                cout << g[from][i] << ' ';
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        cin >> from >> to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    return 0;
}