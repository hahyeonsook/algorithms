#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 1000000;
vector<int> prime;
bool check[MAX + 1] = {false}; // is_prime 연산을 줄이기 위한 변수

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
    for (int i = 3; i < MAX + 1; i++)
    {
        if (is_prime(i))
        {
            prime.push_back(i);
            check[i] = true;
        }
    }

    int n;
    cin >> n;
    while (n != 0)
    {
        int a = 3, b = 3;
        for (int a = 3; a < MAX + 1; a += 2)
        {
            int b = n - a;
            if (check[a] && check[b])
            {
                cout << n << " = " << a << " + " << b << "\n";
                a = MAX + 1;
            }
        }
        cin >> n;
    }
    return 0;
}