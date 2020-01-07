//
// Created by 이승민 on 2020-01-07.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    set<string> temp1;
    set<string> temp2;
    string temp;
    for (int i = 0; i < str1.length() - 1; ++i) {
        if(islower(str1[i]) && islower(str1[i+1])){
            temp = str1[i] + str1[i+1];
            temp1.insert(temp);
            temp.clear();
        }

    }
    for (int i = 0; i < str2.length() - 1; ++i) {
        if(islower(str2[i]) && islower(str2[i+1])) {
            temp = str2[i] + str2[i+1];
            temp2.insert(temp);
            temp.clear();
        }
    }

    set<string>s;
    set_union(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), inserter(s, s.begin()));

    answer = (temp1.size() + temp2.size() - s.size()) * 65536 / s.size();
    return answer;
}

int main(){

    cout << "1: " << solution("FRANCE", "french") << endl;
    cout << "2: " << solution("handshake","shake hands") << endl;
    cout << "3: " << solution("aa1+aa2", "AAAA12") << endl;
    cout << "4: " << solution("E=M*C^2","e=m*c^2") << endl;

    return 0;
}