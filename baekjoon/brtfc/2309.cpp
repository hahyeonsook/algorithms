#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nanjeng(9);
int sum = 0;
bool go()
{
    int temp = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == j)
                continue;
            temp = sum - nanjeng[i] - nanjeng[j];
            if (temp == 100)
            {
                nanjeng[i] = -1;
                nanjeng[j] = -1;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 9; i++)
    {
        cin >> nanjeng[i];
        sum += nanjeng[i];
    }
    if (go())
    {
        sort(nanjeng.begin(), nanjeng.end());
        for (int i = 0; i < 9; i++)
        {
            if (nanjeng[i] != -1)
            {
                cout << nanjeng[i] << '\n';
            }
        }
    }
}