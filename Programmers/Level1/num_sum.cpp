//
// Created by 이승민 on 2019-12-30.
//

#include <iostream>
#include <math.h>

using namespace std;
int solution(int n)
{
    int answer = 0;

    int digit = log10(n);
    for (int i = digit; i >=0 ; --i) {
        int num = n / (pow(10,i));
        answer += num;
        n -= num * (pow(10,i));
    }

    return answer;
}


int main(){

    cout << solution(123) << endl;
    cout << solution(987);

    return 0;
}