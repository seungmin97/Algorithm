//
// Created by 이승민 on 2020-08-25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<bool> visit(n, false);
    vector<int> condition(n, -1);
    queue <int> q;

    sort(path.begin(), path.end());
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; ++i) {
        v[path[i][0]].push_back(path[i][1]);
        v[path[i][1]].push_back(path[i][0]);
    }

    for (int i = 0; i < order.size(); ++i) {
        condition[order[i][1]] = order[i][0];
    }

    int count = 0;
    q.push(0);
    int check = 0;

    while(count != n){

        if(check > n * n / q.size()){
            return false;
        }

        int index = q.front();
        q.pop();

        if(condition[index] == -1){
            for (int i = 0; i < v[index].size(); ++i) {
                if(!visit[v[index][i]]){
                    q.push(v[index][i]);
                }
            }
        }
        else if(!visit[condition[index]]){
            q.push(index);
            check += 1;
            continue;
        }
        else{
            for (int i = 0; i < v[index].size(); ++i) {
                if(!visit[v[index][i]]){
                    q.push(v[index][i]);
                }
            }
        }
        visit[index] = true;


        count++;


    }

    return answer;
}

int main(){


    cout << solution(9, {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}}, {{8,5},{6,7},{4,1}}) << endl;
    cout << solution(9, {{8,1},{0,1},{1,2},{0,7},{4,7},{0,3},{7,5},{3,6}}, {{4,1},{5,2}}) << endl;
    cout << solution(9, {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}}, {{4,1},{8,7},{6,5}}) << endl;
}