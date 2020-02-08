#include <iostream>
#include <string>
using namespace std;
int main()
{
    int alpha[26];
    for (int i = 0; i < 26; i++)
        alpha[i] = -1;
    string w;
    cin >> w;
    for (int i = 0; i < w.length(); i++)
    {
        if (alpha[w[i] - 97] == -1)
            alpha[w[i] - 97] = i;
    }
    for (int i = 0; i < 26; i++)
        cout << alpha[i] << ' ';
    cout << '\n';
}