//
// Created by 이승민 on 2019-12-02.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;

    long long *temp = new long long[N+1];
    temp[0] = 1;
    temp[1] = 1;

    for (int i = 2; i <= N; ++i) {
        temp[i] = temp[i-2] + temp[i-1];
    }

    answer = temp[N] * 2 + temp[N-1] * 2;

    return answer;
}

int main(){

    cout << solution(5) << endl;
    cout << solution(6) << endl;
}