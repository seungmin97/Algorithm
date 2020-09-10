//
// Created by 이승민 on 2020-09-10.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Point{
    int x, y;
    int distance;
};

int main(){

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N);
    vector<vector<int>> result;
    vector<vector<bool>> visit;

    for (int i = 0; i < N; ++i) {
        vector<bool> v_(M, false);
        visit.push_back(v_);

        vector<int> v__(M, 0);
        result.push_back(v__);
    }

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j) {
            v[i].push_back(str[j] - 48);
        }
    }


    queue <Point> q;
    q.push({0, 0, 0});

    while(q.size() != 0){
        Point p = q.front();

        int dx[4] =
    }

    return 0;
}