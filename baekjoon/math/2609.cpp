#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a;
    cin >> b;

    int g = gcd(a, b);
    cout << g << '\n';
    cout << (a * b) / g << '\n';

    return 0;
}