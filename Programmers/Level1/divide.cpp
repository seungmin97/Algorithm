//
// Created by 이승민 on 2019-12-19.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); ++i) {
        if(arr[i] < divisor){
            continue;
        }
        else if(arr[i] % divisor == 0){
            answer.push_back(arr[i]);
        }
    }

    sort(answer.begin(), answer.end());

    if(answer.size() == 0){
        answer.push_back(-1);
        return answer;
    }

    return answer;
}

int main(){

    return 0;
}