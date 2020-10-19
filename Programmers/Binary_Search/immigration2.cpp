//
// Created by 이승민 on 2020-10-19.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    long long left = 0;
    long long right = (long long)times[0] * n;

    while(left <= right){
        long long temp = 0;
        long long mid = (left + right) / 2;
        for (int i = 0; i < times.size(); ++i) {
            temp += (mid / times[i]);
        }
        if(temp >= n){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }

    }

    return answer;
}




int main(){

    cout << solution(11, {3,4,10}) << endl;

    return 0;
}