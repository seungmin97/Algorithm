//
// Created by 이승민 on 2020-07-27.
//

#include <iostream>
/*
#include <string>
#include <vector>
#include <algorithm>

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

    vector<jewerly> je = jewer;
    for (int i = 0; i < jewer.size(); ++i) {
        if(je[i].name == temp){
            je[i].index.push_back(index);
            return je;
        }
    }

    jewerly j;
    j.name = temp;
    j.index.push_back(index);

    je.push_back(j);

    return je;
}


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<jewerly> jewer;
    vector<pair<int, int>> temp;

    for (int i = 0; i < gems.size(); ++i) {
        jewer = find_jewerly(gems[i], i, jewer);
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
                    temp.push_back(make_pair(jewer[i].index[j], jewer[i].index[j]));
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
                        else if(abs(left - temp[j].first) <= abs(right - temp[j].second)){
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
}*/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0); // 정답 리턴을 위한 초기화

    // set을 사용하여 보석의 종류수를 센다.
    unordered_set<string> s;

    for (auto tmp : gems) {
        s.insert(tmp);
    }

    int kind = s.size();

    // map을 사용하여 구간내 보석의 빈도수를 센다.
    unordered_map<string, int> m;
    int start = 0, end = 0;
    int minDist = 0x7fffffff;

    // 투포인터 기법을 사용해 연속된 구간들을 탐색해본다.
    while (1) {
        if (m.size() >= kind) { // 현재 구간이 조건에 맞는다면(모든 종류의 보석을 포함한다면)
            m[gems[start]]--; // 구간을 줄여본다.(맨 앞의 보석을 제거한다.)
            if (m[gems[start]] == 0)
                m.erase(gems[start]);
            start++;
        }
        else if (end == gems.size()) // 현재 구간이 조건에 맞지않고, 마지막 포인터가 범위를 초과하면
            break; // 구간 탐색을 중지한다.
        else { // 현재 구간이 조건에 맞지 않는다면, 마지막 포인터를 증가시켜본다.(맨 뒤에 보석을 추가한다.)
            m[gems[end]]++;
            end++;
        }

        if (m.size() == kind) { // 현재 구간이 조건에 맞는지 확인한다.(모든 종류 보석 포함여부)
            if (abs(end - start) < minDist) { // 조건을 만족하는 최소 구간을 구한다.
                minDist = abs(end - start);
                answer[0] = start + 1;
                answer[1] = end;
            }
        }
    }

    return answer;
}

int main(){

    vector <int> answer;
    answer = solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
    cout << answer[0] << " " << answer[1] << endl;

    answer.erase(answer.begin(), answer.end());
    answer = solution({"AA", "AB", "AC", "AA", "AC"});
    cout << answer[0] << " " << answer[1] << endl;

    answer.erase(answer.begin(), answer.end());
    answer = solution({"XYZ", "XYZ", "XYZ"});
    cout << answer[0] << " " << answer[1] << endl;

    answer.erase(answer.begin(), answer.end());
    answer = solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"});
    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}