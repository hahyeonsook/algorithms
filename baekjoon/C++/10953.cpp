#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int a, b;
        scanf("%d,%d", &a, &b);
        cout << a + b << endl;
    }
}