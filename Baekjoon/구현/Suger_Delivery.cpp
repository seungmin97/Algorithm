//
// Created by 이승민 on 2019-09-23.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    int _5kg = N / 5;
    int _3kg = N / 3;

    int result = 10000;
    for (int i = 0; i <= _5kg; ++i) {
        for (int j = 0; j <= _3kg; ++j) {
            int many = i;
            if(((5 * i) + (3 * j)) == N){
                many += j;

                result = min(many, result);
            }


        }
    }

    if(result != 10000){
        cout << result;
    }
    else{
        cout << -1;
    }
    return 0;
}