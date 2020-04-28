#include <iostream>
#include <vector>
using namespace std;
int n, board[100][100];
bool jump(int y, int x)
{
    //기저 사례: 게임판 밖을 벗어난 경우
    if (y >= n || x >= n)
        return false;
    //기저 사례: 마지막 칸에 도착한 경우
    if (y == n - 1 && x == n - 1)
        return true;
    int jumpSize = board[y][x];
    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}
int cache[100][100];
int jump2(int y, int x)
{
    //기저 사례
    if (y >= n || x >= n)
        return 0;
    if (y == n - 1 && x == n - 1)
        return 1;
    //cache 초기화, memset으로 초기화할 수 있는 것은 0 or -1만 가능
    //메모이제이션
    //답은 cache의 참조형
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    int jumpSize = board[y][x];
    return jump2(y + jumpSize, x) || jump2(y, x + jumpSize);
}
int main()
{
    return 0;
}