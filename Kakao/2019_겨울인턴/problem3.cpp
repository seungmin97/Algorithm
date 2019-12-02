//
// Created by 이승민 on 2019-11-28.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id){

    int answer = 0;


    return answer;
}

int main(){

    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"}) << endl;
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"*rodo", "*rodo", "******"}) << endl;
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"}) << endl;

    return 0;
}