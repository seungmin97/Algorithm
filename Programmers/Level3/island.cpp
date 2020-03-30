//
// Created by 이승민 on 2020-03-28.
//

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector <int> v2){

    return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    int *check = new int[n];
    memset(check, 0, sizeof(int) * n);

    vector<int> temp;
    for (int i = 0; i < costs.size(); ++i) {
        //cout << costs[i][0] << " " << costs[i][1] << " " << costs[i][2] << endl;
        check[costs[i][1]]++;
        check[costs[i][0]]++;
    }

    for (int i = 0; i < n; ++i) {
        if(check[i] == 1){
            for (int j = 0; j < costs.size(); ++j) {
                if(costs[j][1] == i){
                    answer += costs[j][2];
                    costs.erase(costs.begin() + j);
                    break;
                }
            }
            temp.push_back(i);
        }

    }

    int count = temp.size();
    memset(check, 0, sizeof(int) * n);
    for (int i = 0; i < temp.size(); ++i) {
        check[temp[i]] = 1;
    }

    for (int i = 0; i < costs.size(); ++i) {
        if(i == 0 && check[costs[i][0]] == 0){
            check[costs[i][0]] = 1;
            count++;
        }
        else if(check[costs[i][0]] == 0 && check[costs[i][1]] == 0){
            answer += costs[i][2];
            count += 2;
            check[costs[i][0]] = 1;
            check[costs[i][1]] = 1;

            for (int j = i + 1; j < costs.size(); ++j) {
                if(costs[j][0] == costs[i][0] || costs[j][1] == costs[i][0] || costs[j][0] == costs[i][1] || costs[j][1] == costs[i][1]){
                    answer += costs[j][2];
                    if(check[costs[j][0]] == 0){
                        check[costs[j][0]] = 1;
                        count++;
                    }
                    if(check[costs[j][1]] == 0){
                        check[costs[j][1]] = 1;
                        count++;
                    }
                    break;
                }
            }
            continue;
        }

        if(check[costs[i][1]] == 0){
            check[costs[i][1]] = 1;
            count++;
            answer += costs[i][2];
        }

        if(count == n){
            break;
        }
    }

    return answer;
}

int main(){

    //cout << solution(4, {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}}) << endl;
    cout << solution(6, {{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}}) << endl;
    return 0;
}