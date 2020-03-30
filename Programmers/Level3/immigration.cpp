//
// Created by 이승민 on 2020-03-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long left = 0;
    long long right = n * times[times.size() - 1];

    while(left <= right){
        long long mid = (left + right) / 2;

        long long count = 0;

        for (int i = 0; i < times.size(); ++i) {
            count += mid / times[i];
        }

        if(count >= n){
            right = mid - 1;
            answer = mid;
        }
        else{
            left = mid + 1;
        }
    }

    return answer;
}

int main(){

    cout << solution(6, {7,10}) << endl;

    return 0;
}