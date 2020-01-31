#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> s;
    s.push(0);

    return 0;
}