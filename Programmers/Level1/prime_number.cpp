//
// Created by 이승민 on 2019-12-26.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int solution(int n) {
    if(n <= 1){
        return 0;
    }
    int answer = 0;
    int check = 0;

    int *temp = new int[n + 1];
    memset(temp, 0, sizeof(int) * (n + 1));

    for (int i = 2; i <= n; ++i) {
        if(temp[i] != 0){
            continue;
        }
        for (int j = 2; j <= n; ++j){
            if(i * j > n){
                break;
            }

            temp[i*j] = 1;
        }
    }

    for (int i = 2; i < n + 1; ++i) {
        if(temp[i] == 0){
            answer++;
        }
    }

    return answer;
}

int main(){

    //solution(10);

    cout << solution(10) << endl;
    cout << solution(5);

    return 0;
}