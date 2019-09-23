//
// Created by 이승민 on 2019-09-23.
//

#include <iostream>

using namespace std;

int main(){

    int calender[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int x, y;
    cin >> x >> y;

    int day = 0;
    for (int i = 0; i < x; ++i) {
        day += calender[i];
    }
    day += y;

    int result = day % 7;
    if(result == 1){
        cout << "MON";
    }
    else if(result == 2){
        cout << "TUE";
    }
    else if(result == 3){
        cout << "WED";
    }
    else if(result == 4){
        cout << "THU";
    }
    else if(result == 5){
        cout << "FRI";
    }
    else if(result == 6){
        cout << "SAT";
    }
    else{
        cout << "SUN";
    }
    return 0;
}