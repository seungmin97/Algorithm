//
// Created by 이승민 on 2020-03-23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;

    long long *arr = new long long[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; ++i) {
        arr[i] = (arr[i-1] + arr[i-2]) % 1234567;
    }

    answer = arr[n] % 1234567;
    return answer;
}

int main(){

    cout << solution(4) << endl;
    cout << solution(3) << endl;
}