/*
* 상하좌우/대각선으로 인접한 칸들의 글자를 이어서 단어를 찾는 게임이다.
* 주어진 칸에서 시작하여 특정 단어를 찾을 수 있는지 확인하라.
* 1. 몇 분에 문제를 이해했나?
* 2. 몇 분동안 풀이를 생각했나?
* 3. 몇 분동안 코딩했나?
* 4. 몇 분동안 디버깅했나?
*/

#include <iostream>
#include <string>

using namespace std;

const char board[5][5] = {
    {'N', 'N', 'N', 'N', 'S'},
    {'N', 'E', 'E', 'E', 'N'},
    {'N', 'E', 'Y', 'E', 'N'},
    {'N', 'E', 'E', 'E', 'N'},
    {'N', 'N', 'N', 'N', 'N'},
};

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool inRange(int y, int x)
{
    if (y >= 0 && y < 6 && x >= 0 && x < 6)
        return true;
    return false;
}

// 5*5 보글 게임판에서 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string &word)
{
    //기저 사례 1: 시작 위치가 범위 밖이면 무조건 실패
    if (!inRange(y, x))
        return false;
    //기저 사례 2: 첫 글자가 일치하지 않으면 실패
    if (board[y][x] != word[0])
        return false;
    //기저 사례 3: 단어 길이가 1이면 성공
    if (word.size() == 1)
        return true;

    //인접한 여덟 칸을 검사한다.
    for (int direction = 0; direction < 8; ++direction)
    {
        int nextY = y + dy[direction], nextX = x + dx[direction];
        //다음 칸이 범위 안에 있는지, 첫 글자는 일치하는지 확인할 필요가 없다.
        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}

int main()
{
    int y, x;
    string word;

    cin >> x;
    cin >> y;

    cin >> word;

    if (hasWord(y, x, word))
        cout << "Is the word!" << endl;
    else
        cout << "Is not the word." << endl;
    return 0;
}