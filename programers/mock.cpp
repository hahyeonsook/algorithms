#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int one[] = {1, 2, 3, 4, 5};                  // 5
int two[] = {2, 1, 2, 3, 2, 4, 2, 5};         // 8
int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; //10
int score0 = 0, score1 = 0, score2 = 0;

vector<int> answer()
{
    vector<int> answer;
    int max = 0;
    max = (score0 > max) ? score0 : max;
    max = (score1 > max) ? score1 : max;
    max = (score2 > max) ? score2 : max;

    if (score0 == max)
        answer.push_back(1);
    if (score1 == max)
        answer.push_back(2);
    if (score2 == max)
        answer.push_back(3);
    return answer;
}

vector<int> solution(vector<int> answers)
{
    for (int i = 0; i < answers.size(); i++)
    {
        int tmp = answers[i];
        if (tmp == one[i % 5])
            score0 += 1;
        if (tmp == two[i % 8])
            score1 += 1;
        if (tmp == three[i % 10])
            score2 += 1;
    }
    return answer();
}
int main()
{
    vector<int> answers;
    int arr[] = {1, 3, 2, 4, 2};
    for (int i = 0; i < 5; i++)
        answers.push_back(arr[i]);
    vector<int> ans = solution(answers);
    while (!ans.empty())
    {
        cout << ans.back() << ' ';
        ans.pop_back();
    }
    return 0;
}