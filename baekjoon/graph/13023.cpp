#include <iostream>
#include <vector>
using namespace std;
bool a[2000][2000];           // 인접행렬
vector<int> g[2000];          // 인접리스트
vector<pair<int, int>> edges; // 간선리스트

/**
 * A-B, C-D : 간선리스트
 * B-C : 인접행렬
 * D-E : 인접리스트
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        a[from][to] = a[to][from] = true;
        edges.push_back({from, to});
        edges.push_back({to, from});
        g[from].push_back(to);
        g[to].push_back(from);
    }
    m *= 2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //A->B
            int A = edges[i].first;
            int B = edges[i].second;
            //C->D
            int C = edges[j].first;
            int D = edges[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D)
                continue;
            //B->C
            if (!a[B][C])
                continue;
            //D->E
            for (int E : g[D])
            {
                if (A == E || B == E || C == E || D == E)
                    continue;
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
**/

/*
int f = 0;
int go(int n, vector<vector<int>> &e)
{
    if (e[n].back() != -1)
        f += 1;
    //cout << e[n][0] << '\n';
    //cout << n << ' ' << m << '\n';
    if (f > 2)
        return 1;
    while (e[n].back() != -1)
    {
        go(e[n].back(), e);
        e[n].pop_back();
    }
    n += 1;
    if (n > e.size())
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m;
    vector<vector<int>> e(n, vector<int>(m, -1));

    t = m;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
    }
    cout << '\n'
         << go(0, e) << '\n';
    return 0;
}
*/