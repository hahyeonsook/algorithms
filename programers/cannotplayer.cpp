#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    while (!completion.empty())
    {
        if (completion.back() == participant.back())
        {
            completion.pop_back();
            participant.pop_back();
        }
        else
        {
            answer = participant.back();
            participant.pop_back();
        }
    }

    if (!participant.empty())
        answer = participant.back();
    return answer;
}

int main()
{
    vector<string> participant;
    vector<string> completion;
    string partciplayer[] = {"mislav", "stanko", "mislav", "ana"};
    string complplayer[] = {"mislav", "stanko", "ana"};
    for (int i = 0; i < 4; i++)
        participant.push_back(partciplayer[i]);
    for (int i = 0; i < 3; i++)
        completion.push_back(complplayer[i]);

    cout << solution(participant, completion);
    return 0;
}