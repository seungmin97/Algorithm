//
// Created by user on 2019-09-16.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int N;
    cin >> N;

   int length;
   int num = N;
    for (int i = 0; i < 7; ++i) {
        num /= 10;
        if(num == 0){
            length = i;
            break;
        }
    }
    //cout << length << endl;

    //num = N
    for (int i = 1; i <= N; ++i) {
        int temp = i;
        num = i;
        for (int j = 0; j <= length ; ++j) {
            temp += (num % 10);
            num /= 10;
        }

        //cout << i << " " << temp << endl;

        if(temp == N){

            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}