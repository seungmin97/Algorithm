//
// Created by 이승민 on 2020-05-12.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long count = 0;

    long long left = 1;
    long long right = (long long)times[times.size() - 1] * (long long)n;
    long long mid;

    while(left <= right){
        mid = (left + right) / 2;
        count = 0;
        for(int i = 0; i < times.size(); i++){
            count += (long long)(mid / times[i]);
        }

        if(count >= n) {
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    if(answer == 0){
        answer = mid + 1;
    }
    return answer;
}

int main(){

    cout << solution(6, {7,10}) << endl;

    return 0;
}