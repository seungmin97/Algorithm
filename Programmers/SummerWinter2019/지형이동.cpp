//
// Created by 이승민 on 2020-10-08.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int** check(int **arr, vector<vector<int>> land, int height, int x, int y, int num){

    int temp = land[x][y];

    int x_[4] = {0, -1, 0, 1};
    int y_[4] = {1, 0, -1, 0};

    for (int i = 0; i < 4; ++i) {
        int next_x = x + x_[i];
        int next_y = y + y_[i];

        if(next_x < 0 || next_x >= land.size() || next_y < 0 || next_y >= land.size()){
            continue;
        }

        if(height + temp >= land[next_x][next_y] && arr[next_x][next_y] == -1){
            arr[next_x][next_y] = num;
            arr = check(arr, land, height, next_x, next_y, num);
        }
        else{
            continue;
        }
    }
    return arr;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int count = 0;

    int **arr = new int*[land.size()];

    for (int i = 0; i < land.size(); ++i) {
        arr[i] = new int[land.size()];
        memset(arr[i], -1, sizeof(int) * land.size());
    }
    int x = 0, y = 0;
    int num = 0;
    while(count != land.size() * land.size()){
        if(arr[x][y] == -1){
            arr = check(arr, land, height, x, y, num);
            num++;
        }

        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land.size(); ++j) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        if(count %2 == 0){
            x = (x+1) % land.size();
        }
        else{
            y = (y+1) % land.size();
        }


    }

    return answer;
}

int main(){

    //cout << solution({{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}}, 3) << endl;
    cout << solution({{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}}, 1) << endl;

    return 0;
}