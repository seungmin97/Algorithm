x//
// Created by 이승민 on 2019-12-02.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;


    vector<vector<int>> result(triangle.size());
    for (int i = 0; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            result[i].push_back(0);
        }
    }

    result[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            if(j >= 0 && j < triangle[i].size() - 1){
                result[i][j] = max(result[i][j], result[i-1][j] + triangle[i][j]);
            }

            if(j > 0){
                result[i][j] = max(result[i][j], result[i-1][j - 1] + triangle[i][j]);
            }
        }
    }

    for (int i = 0; i < triangle[triangle.size() - 1].size(); ++i) {
        answer = max(answer, result[triangle.size() - 1][i]);
    }

    return answer;
}

int main(){

    vector<vector<int>> triangle = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};

    cout << solution(triangle);
    return 0;
}