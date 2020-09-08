//
// Created by 이승민 on 2020-09-08.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();


    for (int i = 1; i <= s.length() / 2; ++i) {
        string result = "";
        string temp = s.substr(0, i);
        int count = 1;
        for (int j = i; j < s.length(); j += i) {
            if(temp == s.substr(j, i)){
                count++;
            }
            else{

                if(count > 1){
                    result += to_string(count);
                }

                result += temp;
                temp = s.substr(j, i);
                count = 1;
            }
        }

        if(count > 1){
            result += to_string(count);
        }

        result += temp;

        if(result.length() < answer){
            answer = result.length();
        }
    }
    return answer;
}

int main(){

    cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    cout << solution("abcabcdede") << endl;
    cout << solution("abcabcabcabcdededededede") << endl;
    cout << solution("xababcdcdababcdcd") << endl;

    return 0;
}