//https://programmers.co.kr/learn/courses/30/lessons/42587
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool desc(int a, int b)
{
    return b < a;
}
int solution(vector<int> priorities, int location)
{
    int answer = 0, i = 0;
    int max = priorities.size();
    vector<int> output(max, -1);
    vector<int> sorted = priorities;
    sort(sorted.begin(), sorted.end(), desc);

    while (answer < max)
    {
        if (sorted[answer] == priorities[i] && output[i] == -1)
        {
            output[i] = answer;
            answer += 1;
            if (i == location)
                return answer;
        }
        if (i != 0 && i % (max - 1) == 0)
            i = 0;
        else
            i += 1;
    }
    return answer;
}
int main()
{
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    cout << solution(priorities, 0);
    return 0;
}