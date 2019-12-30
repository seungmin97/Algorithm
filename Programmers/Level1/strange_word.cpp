//
// Created by 이승민 on 2019-12-30.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;

    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == ' '){
            index = 0;
            answer+= " ";
            continue;
        }

        if(index%2 == 0){
            answer += toupper(s[i]);
        }
        else{
            answer += tolower(s[i]);
        }
        index++;
    }

    return answer;
}

int main(){

    cout << solution("tRy hello world");

    return 0;
}