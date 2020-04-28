#include <iostream>
#include <vector>
using namespace std;
int lis(const vector<int> &A)
{
    //기저 사례: A가 비었을 때
    if (A.empty())
        return 0;
    int ret = 0;
    //주어진 정수 수열의 모든 원소를 완전 탐색하기 위한 i
    for (int i = 0; i < A.size(); ++i)
    {
        //순 증가하는 부분 수열을 저장할 배열
        vector<int> B;
        //순열 A[i]의 뒤에 올 수 있는 원소를 완전 탐색하기 위한 j
        for (int j = 0; j < A.size(); ++j)
        {
            if (A[i] < A[j])
                B.push_back(A[j]);
        }
        ret = max(ret, 1 + lis(B));
    }
    return ret;
}
int n;
int cache[100], S[100];
//S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환
int lis2(int start)
{
    int &ret = cache[start];
    if (ret != -1)
        return ret;
    //S[start]는 항상 있기 때문에 길이는 최하 1
    ret = 1;
    for (int next = start + 1; next < n; ++next)
    {
        if (S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    }
    return ret;
}
int cache2[101], S2[100];
int lis3(int start)
{
    int &ret = cache2[start + 1];
}
int main()
{
    return 0;
}