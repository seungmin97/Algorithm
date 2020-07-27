//
// Created by 이승민 on 2020-07-20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(string expression) {

    vector<vector<char>> v = {{'*', '+', '-'}, {'*', '-', '+'}, {'+', '*', '-'}, {'+', '-', '*'}, {'-', '*', '+'}, {'-', '+', '*'}};

    long long answer = 0;

    vector<long long> v1;
    vector<char> v2;

    string temp;
    for (int i = 0; i < expression.length(); ++i) {
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
            v2.push_back(expression[i]);
            v1.push_back(atoi(temp.c_str()));
            temp = "";
        }
        else{
            temp += expression[i];
        }
    }
    v1.push_back(atoi(temp.c_str()));

    for (int i = 0; i < v.size(); ++i) {
        vector<long long> temp1 = v1;
        vector<char> temp2 = v2;
        for (int k = 0; k < 3; ++k) {
            for (int j = 0; j < temp2.size(); ++j) {
                if(temp2[j] == v[i][k]){

                    if(temp2[j] == '+'){
                        temp1[j] += temp1[j+1];
                    }
                    else if(temp2[j] == '-'){
                        temp1[j] -= temp1[j+1];
                    }
                    else{
                        temp1[j] *= temp1[j+1];
                    }

                    temp2.erase(temp2.begin() + j);
                    temp1.erase(temp1.begin() + j + 1);

                    j--;
                }
            }
        }
        answer = max(answer, abs(temp1[0]));
    }


    return answer;
}

int main(){

    cout << solution("100-200*300-500+20") << endl;
    cout << solution("50*6-3*2") << endl;

    return 0;
}