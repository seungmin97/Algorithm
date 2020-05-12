//
// Created by 이승민 on 2020-05-12.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;

    sort(budgets.begin(), budgets.end());
    int left = 0;
    int right = budgets[budgets.size() - 1];
    int count = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        count = 0;
        for (int i = 0; i < budgets.size(); ++i) {
            if(budgets[i] <= mid){
                count += budgets[i];
            }
            else{
                count += mid;
            }
        }

        if(count <= M){
            left = mid + 1;
            answer = mid;
        }
        else{
            right = mid - 1;
        }
    }

    return answer;
}

int main(){

    cout << solution({120, 110, 140, 150}, 485) << endl;

    return 0;
}