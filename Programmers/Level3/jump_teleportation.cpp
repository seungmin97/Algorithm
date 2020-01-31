//
// Created by 이승민 on 2020-01-31.
//

#include <iostream>
#include <math.h>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while(1){

        if(n == 1){
            ans+=1;
            break;
        }

        if(n % 2 == 0){
            n /= 2;
        }
        else{
            ans += 1;
            n--;
        }
    }
    return ans;
}

int main(){

    cout << solution(2) << endl;
    cout << solution(6) << endl;
    cout << solution(5000);

    return 0;
}