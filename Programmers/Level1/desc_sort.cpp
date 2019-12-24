//
// Created by 이승민 on 2019-12-24.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), greater<char>());
    answer = s;
    return answer;
}

int main(){

    string s = "Zbcdefg";
    cout << solution(s);
    return 0;
}