//https://programmers.co.kr/learn/courses/30/lessons/42584
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> prices)
{
    int max = prices.size();
    vector<int> answer(max, 0);
    stack<int> s;
    for (int i = 0; i < max; i++)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
        }
    }
    return answer;
}
int main()
{
    vector<int> prices = {
        1, 2, 3, 2, 3};

    vector<int> answer = solution(prices);
    for (int i = 0, max = answer.size(); i < max; i++)
        cout << answer[i] << ' ';
    cout << '\n';
    return 0;
}

// 너무 어렵게 생각하지 말것! 간단하게 나오는 문제가 많음
// 처음 스택으로 푼 문제도 맞는듯!
