//
// Created by 이승민 on 2019-09-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> v;

int max_ = 0;
int check(int i, int temp){

    int end_time = v[i].second;
    int time = i;

    max_ = max(max_, temp);

   /* if(i == (v.size() - 1)){
        temp += 1;
    }
*/
    for (int j = i + 1; j < v.size(); ++j) {
        if(v[j].first >= end_time){
            temp += 1;
            time = j;
            check(time, temp);
        }
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

    sort(v.begin(), v.end());

  /*  for (int i = 0; i < v.size() - 1; ++i) {
        if(v[i].first == v[i + 1].first){
            v.erase(v.begin() + i + 1);
        }
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        if((v[i].second >= v[i + 1].second)&& (v[i + 1].first != v[i + 1].second)){
            v.erase(v.begin() + i);
        }
    }*/

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        check(i, 0);
    }


    cout << max_ + 1;

    return 0;
}