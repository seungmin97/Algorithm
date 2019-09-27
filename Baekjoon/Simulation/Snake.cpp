//
// Created by 이승민 on 2019-09-27.
//

#include <iostream>
#include <cstring>
#include <vector>
#define Max 100

using namespace std;


vector <pair <int, int>> snake;
vector <pair <int, int>> change;

int next_x(char direction, int x_){
    if((direction == 'L') || (direction == 'R')){
        return x_;
    }
    else if(direction == 'D'){
        return (x_ + 1);
    }
    else{
        return (x_ - 1);
    }

}

int next_y(char direction, int y_){
    if((direction == 'U') || (direction == 'D')){
        return y_;
    }
    else if(direction == 'R'){
        return (y_ + 1);
    }
    else{
        return (y_ - 1);
    }

}

int main(){

    int arr[100][100];

    int N;
    cin >> N;

    for (int i = 0; i <= N; ++i) {
        memset(arr[i], 0, Max);
    }


    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;

        arr[x][y] = 1;
    }

    int L;
    cin >> L;
    for (int i = 0; i < L; ++i) {
        int time;
        char direction;
        cin >> time >> direction;
        change.push_back(make_pair(time, direction));
    }

    char direction = 'R';
    int x_= 1, y_ = 1;
    int time = 0;
    snake.push_back(make_pair(x_, y_));
    arr[x_][y_] = -1;

    while(1){

        x_ = next_x(direction, x_);
        y_ = next_y(direction, y_);

        if(time == change[0].first){
            direction = change[0].second;
            change.erase(change.begin() + 0);
        }

        if((x_ <= 0) || (x_ > N) || (y_ <= 0) || (y_ > N)){
            cout << time;
            return 0;
        }
        else if(arr[x_][y_] == -1){
            cout << time;
            return 0;
        }

        snake.push_back(make_pair(x_, y_));
        arr[x_][y_] = -1;

        if(arr[x_][y_] == 0){
            arr[snake[0].first][snake[0].second] = 0;
            snake.erase(snake.begin() + 0);
        }
        else{
            arr[x_][y_] = 0;
        }

        time += 1;

    }

}
