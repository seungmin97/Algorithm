//
// Created by 이승민 on 2019-11-20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int index = -1;
    int temp = number.length() - k;
    while(1){
        int max = -1;
        for (int i = index + 1; i <= number.length() - temp; ++i) {
            int num = int(number[i]) - 48;
            if(num > max && (answer.length() + k >= i)){
                index = i;
                max = int(number[i]) - 48;
            }
        }
        temp--;

        answer += number[index];

        if(answer.length() == number.length() - k){
            return answer;
        }
    }
}

int main(){

    //string number = "0000";
    //int k = 2;
    //return 94

    //string number = "1231234";
    //int k = 3;
    //return 3234

    string number = "4177252841";
    int k = 4;
    //return 775841

    cout << solution(number, k);
    //cout << solution(number, k);

    return 0;
}