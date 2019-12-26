//
// Created by 이승민 on 2019-12-26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        if(n % i == 0){
            answer += i;
        }
    }

    return answer;
}

int main(){

    cout << solution(12) << endl;
    cout << solution(5);

    return 0;
}