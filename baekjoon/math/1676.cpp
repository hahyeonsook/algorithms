#include <iostream>
#include <vector>

using namespace std;
const int MAX = 500;
bool check[MAX + 1] = {false};

bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i <= 500; i++)
    {
        if (is_prime(i))
        {
            check[i] = true;
        }
    }

    int n;
    cin >> n;
    vector<int> factorial;
    for (int i = 1; i <= n; i++)
        factorial.push_back(i);

    int two = 0, five = 0;
    for (int i = 0, m = factorial.size(); i < m; i++)
    {
        if (check[factorial[i]])
        {
            if (factorial[i] == 2)
                two++;
            if (factorial[i] == 5)
                five++;
        }
        else
        {
            while (factorial[i] % 2 == 0)
            {
                two++;
                factorial[i] = factorial[i] / 2;
            }
            while (factorial[i] % 5 == 0)
            {
                five++;
                factorial[i] = factorial[i] / 5;
            }
        }
    }

    two < five ? (cout << two) : (cout << five);

    return 0;
}