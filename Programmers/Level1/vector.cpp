//
// Created by 이승민 on 2019-12-30.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i = 0; i < arr1.size(); i++){
        vector <int> temp;
        for(int j = 0; j < arr1[i].size(); j++){
            int sum = arr1[i][j] + arr2[i][j];
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}

int main(){

    solution({{1,2}, {3,4}}, {{3,4},{5,6}});

    return 0;
}