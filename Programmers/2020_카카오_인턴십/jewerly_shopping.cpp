//
// Created by 이승민 on 2020-07-27.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct jewerly{
    string name;
    vector<int> index;
};


bool cmp(const jewerly &j1, const jewerly &j2 ){
    if(j1.index.size() < j2.index.size()){
        return true;
    }
    return false;
}

bool cmp2(const pair<int, int> &p1, const pair<int, int> &p2){
    if((p1.second - p1.first) < (p2.second - p2.first)){
        return true;
    }

    return false;
}

vector<jewerly> find_jewerly(string temp, int index, vector<jewerly> jewer){

    int check = 0;
    for (int i = 0; i < jewer.size(); ++i) {
        if(jewer[i].name == temp){
            jewer[i].index.push_back(index);
            check = 1;
            return jewer;
        }
    }

    jewerly j;
    j.name = temp;
    j.index.push_back(index);

    jewer.push_back(j);

    return jewer;
}


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<jewerly> jewer;
    vector<pair<int, int>> temp;

    for (int i = 0; i < gems.size(); ++i) {
        find_jewerly(gems[i], i, jewer);
    }

    sort(jewer.begin(), jewer.end(), cmp);

    if(jewer.size() == 1){
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }

    for (int i = 0; i < jewer.size(); ++i) {
        if(i == 0){
            if(jewer[i].index.size() == 1){
                temp.push_back(make_pair(jewer[i].index[0], jewer[i].index[0]));
            }
            else{
                for (int j = 0; j < jewer[i].index.size(); ++j) {
                    jewer = temp.push_back(make_pair(jewer[i].index[j], jewer[i].index[j]));
                }
            }
        }
        else{
            if(jewer[i].index.size() == 1){
                for (int j = 0; j < temp.size(); ++j) {
                    if(jewer[i].index[0] < temp[j].first){
                        temp[j].first = jewer[i].index[0];
                    }
                    else{
                        temp[j].second = jewer[i].index[0];
                    }
                }
            }
            else{
                for (int j = 0; j < temp.size(); ++j) {
                    int left = -1;
                    int checkcheck = 0;
                    int right = -1;

                    for (int k = 0; k < jewer[i].index.size(); ++k) {
                        if(jewer[i].index[k] > temp[j].first && jewer[i].index[k] < temp[j].second){
                            checkcheck = 1;
                           break;
                        }
                        else if(jewer[i].index[k] < temp[j].first){
                            if(left == -1){
                                left = jewer[i].index[k];
                            }
                            else if(left < jewer[i].index[k]){
                                left = jewer[i].index[k];
                            }
                            else{
                                continue;
                            }
                        }
                        else{
                            if(right == -1){
                                right = jewer[i].index[k];
                            }
                            else if(right > jewer[i].index[k]){
                                right = jewer[i].index[k];
                            }
                            else{
                                continue;
                            }
                        }
                    }

                    if(checkcheck == 0){
                        if(left == -1){
                            temp[j].second = right;
                        }
                        else if(right == -1){
                            temp[j].first = left;
                        }
                        else if(abs(left - temp[j].second) >= abs(right - temp[j].first)){
                            temp[j].first = left;
                        }
                        else{
                            temp[j].second = right;
                        }
                    }

                }
            }
        }
    }

    sort(temp.begin(), temp.end(), cmp2);
    answer.push_back(temp[0].first + 1);
    answer.push_back(temp[0].second + 1);

    return answer;
}

int main(){

    vector <int> answer;
    answer = solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
    cout << answer[0] << " " << answer[1] << endl;

    answer = solution({"AA", "AB", "AC", "AA", "AC"});
    cout << answer[2] << " " << answer[3] << endl;

    answer = solution({"XYZ", "XYZ", "XYZ"});
    cout << answer[4] << " " << answer[5] << endl;

    /*answer = solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"});
    cout << answer[6] << " " << answer[7] << endl;*/

    return 0;
}