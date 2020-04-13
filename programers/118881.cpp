/*
* 주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다. 
* 숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 
* 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.
*/
#include <vector>
#include <iostream>
using namespace std;
bool numbers[3000] = {
    false,
};
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums)
{
    int answer = 0;
    int max = nums.size();
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < max; k++)
            {
                if (i == k || j == k)
                    continue;
                int temp = nums[i] + nums[j] + nums[k];
                numbers[temp] = true;
            }
        }
    }
    for (int i = 0; i < 3000; i++)
    {
        if (numbers[i] == true)
        {
            if (isPrime(i))
                answer += 1;
        }
    }
    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << '\n'
         << solution(nums);
    return 0;
}