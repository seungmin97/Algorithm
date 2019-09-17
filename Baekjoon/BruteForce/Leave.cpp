//
// Created by user on 2019-09-16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define Max 15
using namespace std;

vector <pair<int, int>> v(Max);

int max_;
int N;
void work(int i, int profit){


    if((i + v[i].first) <= N){
        profit += v[i].second;
    }

    max_ = max(profit, max_);

    for (int j = i + v[i].first; j < N ; ++j) {
        work(j, profit);
    }
}

int main(){

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < N; ++i) {
        work(i, 0);
    }

    cout << max_;
    return 0;
}