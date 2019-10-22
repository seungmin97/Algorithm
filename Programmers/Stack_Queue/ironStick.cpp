//
// Created by 이승민 on 2019-10-21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;

    for (int i = 0; i < arrangement.size(); ++i) {
        char temp = arrangement[i];
        if(temp == '('){

        }
    }
    return answer;
}

int main(){

    string arrangement = "()(((()())(())()))(())";

    cout << solution(arrangement);
    return 0;
}