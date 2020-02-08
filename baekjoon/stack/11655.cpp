
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    for (char ch : str)
    {
        if (isalpha(ch))
        {
            if ((ch >= 'n' && ch <= 'z') || (ch >= 'N' && ch <= 'Z'))
                ch -= 13;
            else
                ch += 13;
            cout << ch;
        }
        else
            cout << ch;
    }
    return 0;
}
//https://www.acmicpc.net/board/view/13931