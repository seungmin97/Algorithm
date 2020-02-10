//
// Created by 이승민 on 2020-02-07.
//

#include <iostream>
using namespace std;

long long solution(int w,int h)
{
    unsigned long long answer = w * h;

    long double a = 0;
    double b = h;
    a = (-1) * b / w;

    for (int i = 0; i < w; ++i) {
         double temp1 = a * (i) + b;
         double temp2 = a * (i + 1) + b;

        for (int j = temp2; j < temp1; ++j) {
            answer-=1;
        }
    }

    return answer;
}

int main(){

    cout << solution(8, 12) << endl;
    cout << solution(12, 8) << endl;
    cout << solution(4, 5) << endl;

    return 0;
}