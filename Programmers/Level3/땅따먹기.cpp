//
// Created by 이승민 on 2020-02-14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            int temp = land[i][j];
            for (int k = 0; k < 4; ++k) {
                if(j == k){
                    continue;
                }
                else{
                    temp = max(temp, land[i][j] + land[i-1][k]);
                }
            }
            land[i][j] = temp;
        }
    }

    for (int l = 0; l < 4; ++l) {
        answer = max(land[land.size()-1][l], answer);
    }

    return answer;
}

int main(){

    cout << solution({{1,2,3,5},{5,6,7,8},{4,3,2,1}}) << endl;

    return 0;
}