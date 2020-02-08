#include <iostream>
#include <string>
using namespace std;
void g(string str)
{
    int sml = 0, cpt = 0, num = 0, blank = 0;
    for (char ch : str)
    {
        if (ch == ' ')
            blank += 1;
        else if (ch < 64)
            num += 1;
        else if (ch < 97)
            cpt += 1;
        else
            sml += 1;
    }
    cout << sml << ' ' << cpt << ' ' << num << ' ' << blank << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    while (getline(cin, str))
        g(str);
    return 0;
}