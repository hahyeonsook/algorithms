#include <iostream>
#include <string>
using namespace std;
int alpha[26] = {
    0,
};
int main()
{
    string word;
    cin >> word;
    cin.ignore();
    for (char ch : word)
    {
        alpha[ch - 97] += 1;
    }
    for (int i = 0; i < 26; i++)
        cout << alpha[i] << ' ';
    cout << '\n';
    return 0;
}