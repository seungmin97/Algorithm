//
// Created by 이승민 on 2019-11-14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name){
    int check = 0;
    int answer = 0;

    for (int i = 0; i < name.length(); ++i) {
        if((name[i] >= 65) && (name[i] <= 78)){
            answer -= (65 - (int)name[i]);
        }
        else{
            answer += (91 - (int)name[i]);
        }
    }

    answer += name.length() - 1;

    if(name[1] == 'A'){
        answer -= 1;
    }

    return answer;
}