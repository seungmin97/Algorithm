//
// Created by 이승민 on 3/4/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    vector<vector<string>> v(id_list.size(), vector<string>(0));

    string temp;
    int count = 0;
    int index = 0;
    string name = "";

    for (int i = 0; i < report.size(); ++i) {
        istringstream ss(report[i]);
        count = 0;

        while (getline(ss, temp, ' ')){

            if(count == 0){
                name = temp;
                count++;
            } else{
                index = find(id_list.begin(), id_list.end(), temp) - id_list.begin();
            }
        }

        v[index].push_back(name);
        /*if(find(v[index].begin(), v[index].end(), name) == v[index].end()){
            v[index].push_back(name);
        }*/
    }



    for (int i = 0; i < id_list.size(); ++i) {

        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());

        if(v[i].size() < k){
            continue;
        }

        for (int j = 0; j < v[i].size(); ++j) {
            index = find(id_list.begin(), id_list.end(), v[i][j]) - id_list.begin();
            answer[index] += 1;
        }
    }

    return answer;
}


int main(){

    vector <int> result;
    result = solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo","apeach frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    result.clear();

    result = solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    result.clear();

    return 0;
}