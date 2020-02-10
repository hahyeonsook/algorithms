#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string wrd;
    cin >> wrd;
    vector<string> ans;
    for (int i = 0; i < wrd.length(); i++)
    {
        string tmp = wrd;
        ans.push_back(tmp.substr(i));
    }
    sort(ans.begin(), ans.end());

    for (string str : ans)
        cout << str << '\n';
    return 0;
}