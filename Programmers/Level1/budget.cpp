//
// Created by 이승민 on 2020-01-01.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;

    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); ++i) {
        sum += d[i];

        if(sum > budget){
            return i;
        }
        else if(sum == budget){
            return i+1;
        }
    }

    return d.size();
}

int main(){

    cout << solution({1,3,2,5,4}, 9) << endl;
    cout << solution({2,2,3,3}, 10);

    return 0;
}