//
// Created by 이승민 on 2020-01-19.
//

#include <iostream>
#include <math.h>
#define logB(x, base) log(x)/log(base)

using namespace std;

int change(int num){
    if(num % 2 == 0){
        num /= 2;
    }
    else{
        num += 1;
        num /= 2;
    }
    return num;
}

int solution(int n, int a, int b)
{
    int temp = 0;
    int answer  = 0;

    if(a > b){
        temp = b;
        b = a;
        a = temp;
    }

    temp = n;
    int count = 0;

    while(1){
        if(a <= (temp/2) && b > (n/2)){
            return logB(n,2.0);
        }
        else{
            temp /= 2;
            a = change(a);
            b = change(b);
            count++;
            if(a == b){
                return count;
            }
        }
    }

}

int main(){

    cout << solution(16,3,16);

    return 0;
}