//
// Created by 이승민 on 2020-03-09.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> v, int N){

    int index = 0;
    for (int i = 1; i < N; ++i) {
        v[i] += v[i - 1];
        v[i * N] += v[(i - 1) * N];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            v[i * N + j] += min(v[i * N + j - 1], v[(i - 1) * N + j]);
        }
    }
    return v[N * N - 1];
}


int main(){

    vector<int> result;
    while(1){

        int N;
        cin >> N;

        if(N == 0){
            break;
        }

        vector<int> v(N * N);
        for (int i = 0; i < N * N; ++i) {
            cin >> v[i];
        }

        result.push_back(solution(v, N));
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << "Problem " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}