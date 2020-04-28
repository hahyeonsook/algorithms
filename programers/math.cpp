#include <iostream>
#include <vector>
using namespace std;
int solution(int n)
{
    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = i; j <= n; ++j)
        {
            sum += j;
            if (sum == n)
            {
                answer += 1;
                break;
            }
        }
    }
    return answer;
}
int main()
{
    cout << solution(15);
    return 0;
}