#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{

    int answer = 0;
    int size = board.size() - 1;
    vector<int> basket;

    for (int j : moves)
    {
        int i = 0;
        j -= 1;

        while (i < size && board[i][j] == 0)
            i += 1;
        if (board[i][j] != 0)
        {
            if (!basket.empty() && basket.back() == board[i][j])
            {
                answer += 2;
                basket.pop_back();
            }
            else
                basket.push_back(board[i][j]);
            board[i][j] = 0;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> board(5, vector<int>(5));
    int arr[5][5] = {{0, 0, 0, 0, 0},
                     {0, 0, 1, 0, 3},
                     {0, 2, 5, 0, 1},
                     {4, 2, 4, 4, 2},
                     {3, 5, 1, 3, 1}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = arr[i][j];
        }
    }
    vector<int> moves;
    int mv[8] = {1, 5, 3, 5, 1, 2, 1, 4};
    for (int i : mv)
        moves.push_back(i);

    cout << solution(board, moves);
}

/**
 * https://simmmmmk.tistory.com/21
 * https://hyeonstorage.tistory.com/324
 * https://blockdmask.tistory.com/70
**/