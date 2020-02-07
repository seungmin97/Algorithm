//
// Created by 이승민 on 2020-02-07.
//

#include <iostream>
using namespace std;

long long solution(int w,int h)
{
    long long answer = w * h;

    long double a = 0, b = 0;
    b = h;
    a = (-1) * (b / w);
    //cout << a << " " << b << " ";

    for (int i = 0; i < w; ++i) {
        long double temp1 = a * (i) + b;
        long double temp2 = a * (i + 1) + b;
        double difference = temp1 - temp2;

        int temp = 0;
        while(temp <= difference){
            temp++;
        }

        answer -= temp;
    }

    return answer;
}

int main(){

    cout << solution(8, 12) << endl;
    cout << solution(4, 5) << endl;

    return 0;
}