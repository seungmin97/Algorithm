//
// Created by 이승민 on 2020-01-02.
//

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int check(string skill, string temp){
    int index = -1;
    int *is = new int[skill.length()];
    /*memset(is, 0, sizeof(int) * skill.length());

    for (int i = 0; i < temp.length(); ++i) {
        if(skill[0] == temp[i]){
            index = i;
            is[0] = 1;
            break;
        }
    }

    for (int j = 1; j < skill.length(); ++j) {
        for (int k = index+1; k < temp.length(); ++k) {
            if(skill[j] == temp[k]){
                if(is[j-1] == 0){
                    return 0;
                }
                is[j] = 1;
                index = k;
                break;
            }
        }
    }
    return 1;*/

    memset(is,-1,sizeof(int) * skill.length());
    for (int i = 0; i < skill.length(); ++i) {
        for (int j = 0; j < temp.length(); ++j) {
            if(skill[i] == temp[j]){
                is[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < skill.length()-1; ++i) {
        if(is[i+1] != -1 && (is[i+1] < is[i])){
            return 0;
        }
        else if(is[i] == -1 && is[i+1] != -1){
            return 0;
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