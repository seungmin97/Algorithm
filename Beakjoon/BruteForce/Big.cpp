//
// Created by user on 2019-09-16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#define MAX 50
using namespace std;

int main(){

    int N;
    cin >> N;

    vector <pair <int, int>> v(MAX);

    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    //sort(v.begin(), v.end(), greater<pair<int, int>>());

    int arr[MAX];
    for (int i = 0; i < MAX; ++i) {
        arr[i] = 1;
    }
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N ; ++j) {
            if((v[i].first < v[j].first) && (v[i].second < v[j].second)){
                arr[i] += 1;
            }
            else if((v[i].first > v[j].first) && (v[i].second > v[j].second)){
                arr[j] += 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}