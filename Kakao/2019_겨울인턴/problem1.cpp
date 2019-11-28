//
// Created by 이승민 on 2019-11-28.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves, int n) {

    int answer = 0;
    vector<int> temp;

    for (int i = 0; i < moves.size(); ++i) {
        int index = moves[i] - 1;

        for (int j = 0; j < n; ++j) {
            if(board[j][index] == 0){
                continue;
            }
            else{
                temp.push_back(board[j][index]);
                board[j][index] = 0;
                break;
            }
        }
    }

    int index = 0;
    while(index < temp.size() - 1){
        if(temp[index] == temp[index+1]){
            temp.erase(temp.begin() + index);
            temp.erase(temp.begin() + index);
            index--;
            answer+=2;
        }
        else{
            index++;
        }
    }
    return answer;
}

int main(){

    int n = 5;
    vector<vector<int>> board= {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};

    cout << solution(board, moves, n);
    return 0;
}