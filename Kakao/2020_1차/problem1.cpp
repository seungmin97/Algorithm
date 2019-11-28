//
// Created by 이승민 on 2019-11-21.
//

#include <iostream>

using namespace std;

int change(string s, int i){

    string temp = s.substr(0,i);
    int count = 1;
    int start = 0;
    for (int j = 0 + i; j < s.length(); j++) {
        string next = s.substr(j, i);

        if(next == temp){
            count++;

            j = j + i;
        }
        else{

            temp = next;
        }

    }
    
}

int solution(string s){

    int result = s.length();

    for (int i = 1; i <= s.length() / 2; ++i) {
        result = min(change(s, i), result);
    }

    return result;
}

int main(){

     cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    cout << solution("abcabcdede") << endl;
    cout << solution("abcabcabcabcdededededede") << endl;
    cout << solution("xababcdcdababcdcd") << endl;

    //7 9 8 14 17
    return 0;
}