#include <iostream>
#include <cctype>
#include <string>
using namespace std;
const string INVALID = "invalid";
template <typename T, typename P>
T remove_if(T beg, T end, P pred)
{
    T dest = beg;
    for (T itr = beg; itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}
string first(string word)
{
    string answer = "";
    if (isinlower(word))
    {
        int pos = wherelower(word);
        word.erase(remove_if(word.begin(), word.end(), word[pos]), word.end());

        if (isinlower(word))
            answer = second(word);
        else
            answer = word;
    }
    else
        answer = word;
    return answer;
}
string second(string word)
{
    string answer = word;
    int last = word.length() - 1;

    //마지막 소문자와 같은지, 같으면 소문자 제거하고 first로 보내기
    if (word[0] == word[last])
        answer = first(word.substr(1, last - 1));
    else //같지 않으면 두 개이상 단어
    {
        //같은 문자까지 잘라서 보내줌
        int pos = word.find(word[0], 1);
        string other = word.substr(1, pos - 1);
        answer = first(other);

        word = word.substr(pos + 1, last);
        if (islower(word[0]))
            word = second(word);
        answer = " " + first(answer);
    }
    return answer;
}
string removech(string word, char ch)
{
    string answer = "";

    return answer;
}
int wherelower(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (islower(sentence[i]))
            return i;
    }
    return -1;
}
bool isinlower(string sentence)
{
    for (char ch : sentence)
    {
        if (islower(ch))
            return true;
    }
    return false;
}
string solution(string sentence)
{
    string answer = "";

    //소문자가 있는지 확인
    if (isinlower(sentence))
    {
        if (islower(sentence[0]))
            answer = second(sentence);
        else
            answer = first(sentence);
    }
    else
        answer = INVALID;
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string sentence;
    cin >> sentence;
    cout << solution(sentence) << '\n';
    return 0;
}