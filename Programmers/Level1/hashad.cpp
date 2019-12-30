//
// Created by 이승민 on 2019-12-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int digit = log10(x);
    int num = 0;
    int temp = x;
    for (int i = digit; i >= 0 ; --i) {
        int sum = (temp / pow(10,i));
        if(sum == 0){
            continue;
        }
        num += sum;

        temp -= sum * pow(10,i);

        if(temp == 0){
            break;
        }
    }

    if(x % num != 0){
        answer = false;
    }
    return answer;
}


int main(){

    cout << solution(1002) << endl;
    cout << solution(15) << endl;
    cout << solution(16) << endl;
    cout << solution(17);

    return 0;
}