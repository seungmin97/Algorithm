//
// Created by 이승민 on 2020-08-07.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;

    int** arr = new int*[board.size()];
    for (int i = 0; i < board.size(); ++i) {
        arr[i] = new int[board.size()];
        memset(arr[i], 0, sizeof(int) * board.size());
    }

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if(board[i][j] == 1){
                continue;
            }

            else{
                
            }
        }
        cout << endl;
    }

    return answer;
}

int main(){

    //cout << solution({{0,0,0},{0,0,0},{0,0,0}}) << endl;
    //cout << solution({{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},
    //                  {0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0}{1,0,0,0,0,0,0,0}}) << endl;
    cout << solution({{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}}) << endl;
    //cout << solution({{0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,},{0,1,0,0,0,1},{0,0,0,0,0,0}})

    return 0;
}