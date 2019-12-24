//
// Created by 이승민 on 2019-12-24.
//

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";

    for (int i = 0; i < seoul.size(); ++i) {
        if(seoul[i] == "Kim"){
            answer += to_string(i);
            answer += "에 있다";
            break;
        }
    }

    return answer;
}

int main(){

    cout << solution({"Jane", "Kim"});

    return 0;
}