//
// Created by 이승민 on 2019-09-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> v;

bool cmp(const pair <int, int> &a, const pair <int, int> &b){
    if(a.second < b.second){
        return true;
    }
    else if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return false;
    }
}

int main(){

    int N;
    cin >> N;
    int start, end;
    for (int i = 0; i < N; ++i) {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), cmp);


    int cnt = 1;
    int time = v[0].second;
    for (int i = 1; i < v.size(); ++i) {
        if(v[i].first >= time){
            time = v[i].second;
            cnt += 1;
        }
    }

    cout << cnt;
    return 0;
}