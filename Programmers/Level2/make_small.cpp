//
// Created by 이승민 on 2020-01-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), less<int>());

    for (int i = 0; i < A.size(); ++i) {
        answer += A[i] * B[A.size() - i - 1];
    }

    return answer;
}

int main(){

    cout << solution({1,4,2}, {5,4,4}) << endl;
    cout << solution({1,2}, {3,4});

    return 0;
}