//
// Created by 이승민 on 2020-01-02.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(string skill, string temp){

    int answer_ = 0;
    int index = -1;

    for (int h = 0; h < temp.length(); ++h) {
        if(skill[0] == temp[h]){
            index = h;
            break;
        }
    }

    if(index == -1){
        return 0;
    }

    for (int j = 1; j < skill.length(); ++j) {
        for (int k = 0; k < temp.length(); ++k) {
            if(skill[j] == temp[k]){
                if(index > k){
                    return 0;
                }
                index = k;
                break;
            }
        }
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); ++i) {
        answer += check(skill, skill_trees[i]);
    }
    return answer;
}

int main(){

    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"});

    return 0;
}