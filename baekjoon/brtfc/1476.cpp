//https://www.acmicpc.net/problem/1476
#include <iostream>
using namespace std;
int main()
{
    int e, s, m;
    cin >> e >> s >> m;
    int tmp = e;

    if (e == s && e == m)
        cout << e << '\n';
    else
    {
        s -= tmp;
        m -= tmp;
        e -= tmp;

        for (int i = 1;; i++)
        {
            if (e == s && s == m && e == m)
            {
                cout << tmp + e << '\n';
                break;
            }
            e += 15;
            if (e > s)
                s += 28;
            if (e > m)
                m += 19;
        }
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int main() {
    int E, S, M;
    cin >> E >> S >> M;
    int e=1, s=1, m=1;
    for (int i=1;; i++) {
        if (e == E && s == S && m == M) {
            cout << i << '\n';
            break;
        }
        e += 1;
        s += 1;
        m += 1;
        if (e == 16) {
            e = 1;
        }
        if (s == 29) {
            s = 1;
        }
        if (m == 20) {
            m = 1;
        }
    }
    return 0;
}
*/
