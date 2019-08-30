//
// Created by 이승민 on 2019-08-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    int size = skill.size();
    int num = skill_trees.size();

    vector <vector <int>> v(num);
    v.assign(num, vector<int>(size, 0));

    for (int i = 0; i < num; ++i) {
      int index = 0;
      int length = skill_trees[i].length();
        for (int j = 0; j < size; ++j) {
            v[i][index++] = skill_trees[i].find(skill[j]);

            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    answer = num;
    //cout << answer;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < size; ++j) {
            if(j == 0 && v[i][j] == -1){
                answer -= 1;
                break;
            }
            else if(j == 0){
                continue;
            }
            else if(v[i][j] == -1){
                int temp = 0;
                for (int k = j; k < size; ++k) {
                    if(v[i][k] != -1){
                        temp += 1;
                    }
                }

                if(temp != 0){
                    answer -= 1;
                    break;
                }
            }
            else{
                if(v[i][j] < v[i][j - 1]){
                    answer -= 1;
                    break;
                }
            }
        }
    }

    return answer;
}

int main() {

    string skill = "ABCDE";
    vector <string> skill_tree(2);

    skill_tree[0] = "ABC";
    skill_tree[1] = "AB";

    cout << solution(skill, skill_tree);

}