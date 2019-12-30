//
// Created by 이승민 on 2019-12-30.
//

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for(int i = 0; i < phone_number.length() ; i++){
        if(i < phone_number.length() - 4){
            answer += "*";
        }
        else{
            answer += phone_number[i];
        }
    }
    return answer;
}