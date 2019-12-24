//
// Created by 이승민 on 2019-12-24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if(s.length() == 4 || s.length() == 6){
        for(int i = 0; i <s.length(); i++){
            if(s[i] < 48 || s[i]  > 57){
                answer = false;
                break;
            }
        }
    }
    else{
        return false;
    }

    return answer;
}

int main(){

    cout << solution("a234");
    cout << solution("1234");

    return 0;
}