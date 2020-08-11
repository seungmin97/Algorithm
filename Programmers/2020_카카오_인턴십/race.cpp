//
// Created by 이승민 on 2020-08-07.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct Point{
    int x, y, direction, price;
};

int solution(vector<vector<int>> board) {
    int answer = 0;

    bool **map = new bool*[board.size()];
    for (int i = 0; i < board.size(); ++i) {
        memset(map[i], false, sizeof(bool) * board.size());
    }


    queue<Point> q;
    q.push({0, 0, -1, 0});
    map[0][0] = 1;

    //오, 왼, 위, 아래
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    while(q.size() != 0){
        Point point = q.front();

        if(point.x == board.size() - 1 && point.y == board.size() - 1) {
            answer = min(answer, point.price);
            continue;
        }
        
        for (int i = 0; i < 4; ++i) {
            int x = point.x + dx[i];
            int y = point.y + dy[i];

            if (x < 0 || x >= board.size() || y < 0 || y >= board.size() || board[x][y] == 1) {
                continue;
            }

            int new_cost = 0;
            if (point.direction == i || point.direction == -1) {
                new_cost = point.price + 100;
            } else {
                new_cost = point.price + 600;
            }

            if (map[x][y] == 0) {
                map[x][y] = new_cost;
                q.push({x, y, i, new_cost});
            } else if (map[x][y] >= new_cost) {
                map[x][y] = new_cost;
                q.push({x, y, i, new_cost});
            }
        }
        q.pop();
    }

    answer = board[board.size()-1][board.size() - 1];
    return answer;
}



int main(){

    cout << solution({{0,0,0},{0,0,0},{0,0,0}}) << endl;
    //cout << solution({{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},
    //                  {0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0}{1,0,0,0,0,0,0,0}}) << endl;
    //cout << solution({{0,0,1,0},{0,0,0,0},{0,1,0,1},{1,0,0,0}}) << endl;
    //cout << solution({{0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,},{0,1,0,0,0,1},{0,0,0,0,0,0}})

    return 0;
}