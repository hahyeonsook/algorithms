#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int calculate(vector<int> &a)
{
    int sum = 0;
    for (int i = 1; i < a.size(); i++)
        sum += abs(a[i] - a[i - 1]);
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int ans = 0;
    do
    {
        int tmp = calculate(a);
        ans = max(ans, tmp);

    } while (next_permutation(a.begin(), a.end()));
    cout << ans << '\n';

    return 0;
}