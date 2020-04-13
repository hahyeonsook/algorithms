#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights)
{
    int size = heights.size();
    vector<int> answer(size, 0);
    for (int i = size - 1; i >= 0; i--)
    {
        vector<int> h(heights);
        int from = h.back();
        h.pop_back();

        while (from > h.back())
            h.pop_back();

        if (!h.empty())
            answer[i] = h.size();
        else
            answer[i] = 0;
        heights.pop_back();
    }
    return answer;
}

int main()
{
    int h[5] = {6, 9, 5, 7, 4};
    vector<int> heights;
    for (int i = 0; i < 5; i++)
    {
        heights.push_back(h[i]);
    }
    vector<int> answer = solution(heights);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    return 0;
}