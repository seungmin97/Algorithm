//
// Created by 이승민 on 2020-10-19.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> v_;


int check(int i, int j, int N){
    int answer = 1;

    v_[i][j] = true;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];

        if(x < 0 || y < 0 || x >= N || y >= N){
            continue;
        }

        if(v[x][y] == 1 && !v_[x][y]){
            answer += check(x,y,N);
        }

    }

    return answer;
}

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        vector <bool> v1(N, false);
        v_.push_back(v1);

        vector<int> v2;
        string str;
        cin >> str;

        for (int j = 0; j < N; ++j) {
            v2.push_back(str[j]-48);
        }

        v.push_back(v2);
    }

    vector<int> result;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(v[i][j] == 1 && !v_[i][j]){
                result.push_back(check(i, j, N));
            }
        }
    }

    cout << result.size() << endl;
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
}