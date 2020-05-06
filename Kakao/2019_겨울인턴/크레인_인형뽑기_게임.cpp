//
// Created by 이승민 on 2020-05-06.
//

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct que{
    queue<int> q;
};

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<queue<int>> v;

    for (int i = 0; i < board.size(); ++i) {
        queue <int> q;
        for (int j = 0; j < board[i].size(); ++j) {
            if(board[j][i] != 0){
               q.push(board[j][i]);
            }
        }
        v.push_back(q);
    }

    stack<int>s;

    for (int i = 0; i < moves.size(); ++i) {
        int temp = v[moves[i]-1].front();
        v[moves[i]-1].pop();

        if(s.size() != 0 && s.top() == temp){
            answer++;
            s.pop();
        }
        else if(temp == 0){
            continue;
        }
        else{
            s.push(temp);
        }
    }

    return answer * 2;
}

int main(){
    int n = 5;
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    cout << solution(board, moves);

    return 0;
}