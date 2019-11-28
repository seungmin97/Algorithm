//
// Created by 이승민 on 2019-11-28.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){

    return a.size() < b.size();
}

void solution(vector<vector<int>> temp){

    vector<int> answer;
    sort(temp.begin(), temp.end(), cmp);

    answer.push_back(temp[0][0]);

    vector<int>::iterator it;
    for (int i = 1; i < temp.size(); ++i) {
        for (int j = 0; j < temp[i].size(); ++j) {
            it = find(answer.begin(), answer.end(), temp[i][j]);
            if(it == answer.end()){
                answer.push_back(temp[i][j]);
                break;
            }
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i];
    }
}


int main(){

    vector<vector<int>> temp = {{4,2,3}, {3}, {2,3,4,1}, {2,3}};

    solution(temp);

    return 0;
}