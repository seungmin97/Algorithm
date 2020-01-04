//
// Created by 이승민 on 2020-01-04.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(int n) {
    string answer = "";

    //자릿수구하기
    int num = 3;
    int digit = 1;
    while(1){
        if(num >= n){
            break;
        }
        digit++;
        num += pow(3,digit);
    }

    //자리수 시작하는 숫자
    num -= pow(3, digit);
    num += 1;

    //n이 자릿수의 몇번째인지
    int num_index = n - num + 1;
    int temp = pow(3,digit);

    int count = 0;
    while(count != (digit)){
        if(num_index <= temp/3){
            answer += "1";
        }
        else if(num_index <= temp / 3 * 2){
            answer += "2";
            num_index -= temp/3;
        }
        else{
            answer += "4";
            num_index -= (temp/3)*2;
        }

        temp/=3;
        count++;
    }

    return answer;
}

int main(){

    cout << solution(1) << endl;
    cout << solution(2) << endl;
    cout << solution(3) << endl;
    cout << solution(4) << endl;
    cout << solution(5) << endl;
    cout << solution(6) << endl;
    cout << solution(7) << endl;
    cout << solution(500000000) << endl;

    return 0;
}