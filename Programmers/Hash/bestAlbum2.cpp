//
// Created by 이승민 on 2020-04-14.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> p1, pair <string, int> p2){
    return p1.second >= p2.second;
}

bool cmp1(pair<pair<string, int>, int> p1, pair<pair<string, int>, int> p2){
    return p1.first.second >= p2.first.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map <string, int> um;
    vector<pair<pair<string, int>, int>> vec;
    for (int i = 0; i < genres.size(); ++i) {
        if(um.count(genres[i]) == 0){
            um.insert(make_pair(genres[i], plays[i]));

        }
        else{
            um[genres[i]] += plays[i];
        }
        vec.push_back(make_pair(make_pair(genres[i], plays[i]), i));
    }

    sort(vec.begin(), vec.end(), cmp1);

    vector<pair<string, int>> v;
    copy(um.begin(), um.end(), back_inserter<vector<pair<string, int>>>(v));
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    int count = 0;
    while(count < v.size()){
        int num = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if(num == 2){
                break;
            }
            if(v[count].first == vec[i].first.first){
                answer.push_back(vec[i].second);
            }

            num++;
        }
        count++;
    }

    return answer;
}

int main(){

    vector <string> generes = {"classic", "pop", "classic", "classic", "pop"};
    vector <int> plays = {500, 600, 150, 800, 2500};

    //vector <string> generes = {"classic", "pop", "classic", "classic", "pop", "zazz", "zazz"};
    //vector <int> plays = {500, 600, 150, 800, 2500, 2100, 1000};

    vector <int> result = solution(generes, plays);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }


    return 0;
}