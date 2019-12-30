//
// Created by 이승민 on 2019-12-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int num) {
    int answer = 0;

    double num_ = num;
    for (int i = 0; i < 500; ++i) {

        if(num_ == 1){
            return i;
        }

        if(fmod(num_, 2) == 0){
            num_ /= 2;
        }
        else{
            num_ *= 3;
            num_ += 1;
        }
    }

    return -1;
}

int main(){

    cout << solution(6) << endl;
    cout << solution(16) << endl;
    cout << solution(626331);

    return 0;
}