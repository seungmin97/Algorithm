//
// Created by 이승민 on 2019-11-21.
//

#include <iostream>

using namespace std;

int change(string s, int i){

    
}

int solution(string s){

    int result = s.length();

    for (int i = 1; i <= s.length() / 2; ++i) {
        result = min(change(s, i), result);
    }

    return result;
}

int main(){

    cout << solution("aabbaccc");
    cout << solution("ababcdcdababcdcd");
    cout << solution("abcabcdede");
    cout << solution("abcabcabcabcdededededede");
    cout << solution("xababcdcdababcdcd")

    //7 9 8 14 17
    return 0;
}