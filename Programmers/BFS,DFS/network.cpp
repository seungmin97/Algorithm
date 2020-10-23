//
// Created by 이승민 on 2020-10-23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check[201] = {false};

void dfs(int i, vector<vector<int>> computers, int n){

    check[i] = true;

    for(int k = 0; k < n; k++){
        if(i == k){
            continue;
        }

        if(!check[k] && computers[i][k]){
            dfs(k, computers, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i = 0; i < n; i++){
        if(!check[i]){
            answer++;
            dfs(i, computers, n);
        }
    }

    return answer;
}