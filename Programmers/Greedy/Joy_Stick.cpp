//
// Created by 이승민 on 2019-11-14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void calculate(char temp){
    if((temp >= 65) && (temp <= 78)){
        answer -= (65 - (int)temp);
    }
    else{
        answer += (91 - (int)temp);
    }
}

int find(vector <int> check, int index, int length){

    for (int i = 1; i < length; ++i) {

        int right = (index + i) % length;
        int left;
        if(index == 0){
            left = length - 1;
        }
        else{
            left = index - 1;
        }

        if(check[right] * check[left] == 1){
            continue;
        }
        else{
            if(check[right] == 1){
                answer += i;
                return left;
            }
            else{
                answer += i;
                return right;
            }

        }
    }
}

int solution(string name){
    int index = 0;
    int length = name.length();

    //바꾼 갯수 확인
    int count = 0;

    //A는 바꿀 필요 없으니 바꿨다고 체크
    vector <int> check(length, 0);
    for (int i = 0; i < length; ++i) {
        if(name[i] == 'A'){
            count++;
            check[i] = 1;
        }
    }

    while(count != length){
        count++;
        check[index] = 1;
        calculate(name[index]);
        index = find(check, index, length);
    }


    return answer;
}

int main(){

    //cout << solution("JEROEN");
    //cout << solution("JAN");
    cout << solution("CANAAAAANAN");
    return 0;
}