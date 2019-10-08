//
// Created by 이승민 on 2019-10-07.
//

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int score = 0;
int score_previous = 0;
int num = 0;

int score_calculate(string str, int num_, int i){
    int check = 0;
    if(str[i + 1] == '*'){
        score += num_;
        score += score_previous;
        score_previous = num_ * 2;
        check = 1;
    }
    else if(str[i + 1] == '#'){
        score -= num_ * 2;
        score_previous = num_ * (-1);
        check = 1;
    }
    else{
        score_previous = num_;
        check = 0;
    }
    return check;
}
int main(){

    string str;
    cin >> str;

    int check = 0;
    string temp;
    for (int i = 0; i < str.length(); ++i) {

        num = atoi(temp.c_str());

        if(str[i] == 'S'){
            int num_ = num;
            score += num_;
            check = score_calculate(str, num_, i);
        }
        else if(str[i] == 'D'){
            int num_ = num * num;
            score += num_;
            check = score_calculate(str, num_, i);
        }
        else if(str[i] == 'T'){
            int num_ = num * num * num;
            score += num_;
            check = score_calculate(str, num_, i);
        }
        else{
            temp += str[i];
            check = 0;
            continue;
        }

        if(check == 1){
            i++;
        }
        temp = "";
    }

    cout << score;

    return 0;
}