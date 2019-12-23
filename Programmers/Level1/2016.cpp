//
// Created by 이승민 on 2019-12-19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string temp[7] = {"SUN","MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int count[12] = {31, 29, 31, 30, 31,30,31,31,30,31,30,31};
    int day = b;

    for (int i = 0; i < a-1; ++i) {
        day += count[i];
    }

    answer = temp[(day%7+4)%7];

    return answer;
}

int main(){

    cout << solution(5, 24);

    return 0;
}