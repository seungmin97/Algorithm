//
// Created by 이승민 on 2020-01-01.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<double, int> &p1, const pair<double, int> &p2){
    if(p1.first > p2.first){
        return true;
    }
    else if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    else{
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    double *num = new double[stages.size()];
    memset(num, 0.0, sizeof(double) * stages.size());

    for (int i = 0; i < stages.size(); ++i) {
        num[stages[i]-1]++;
    }

    int numerator = 0;
    int denominator = stages.size();
    vector <pair<double, int>> result;

    for (int i = 0; i < N; ++i) {
        if(denominator != 0){
            result.push_back(make_pair(num[i] / denominator, i));
            denominator -= num[i];
        }
        else{
            result.push_back(make_pair(0.0, i));
        }
    }

    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); ++i) {
        answer.push_back(result[i].second+1);
    }
    return answer;
}

int main(){

    vector <int> result;
    result = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    result.erase(result.begin(), result.begin() + result.size());

    result = solution(4, {4,4,4,4,4});
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}