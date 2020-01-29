//
// Created by 이승민 on 2020-01-29.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;

    sort(budgets.begin(), budgets.end());
    int index = budgets.size() / 2;

    int left = 0;
    int right = budgets[budgets.size() - 1];

    while(left <= right){
        int mid = (left + right) / 2;

        int sum = 0;
        for (int i = 0; i < budgets.size(); ++i) {
            if(mid > budgets[i]){
                sum += budgets[i];
            }
            else{
                sum += mid;
            }
        }

        if(sum <= M){
            answer = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return answer;
}

int main(){

    cout << solution({120, 110, 140, 150}, 485);

    return 0;
}