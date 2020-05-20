//
// Created by 이승민 on 2020-05-20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int check(int distance, vector<int> rocks, int n, int mid){
    int count = 0;
    int prev = 0;
    for (int i = 0; i < rocks.size(); ++i) {

        if(rocks[i] - prev < mid){
            count++;
        }
        else{
            prev = rocks[i];
        }
    }

    if(distance - rocks[rocks.size() - 1] < mid){
        count++;
    }

    return count;
}


int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    int left = 0;
    int right = distance;
    int mid = 0;

    while(left <= right){
        mid = (left + right) / 2;
        int count = check(distance, rocks, n, mid);

        if(count <= n){
            left = mid + 1;
            answer = mid;
        }
        else{
            right = mid - 1;
        }
    }

    return answer;
}

int main(){

    cout << solution(25, {2, 14, 11, 21, 17}, 2) << endl;

    return 0;
}