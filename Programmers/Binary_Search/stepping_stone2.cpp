//
// Created by 이승민 on 2020-10-19.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());

    int left = 0;
    int right = distance;

    while(left <= right){
        int mid = (left + right) / 2;

        int prev = 0;
        int count = 0;
        for (int i = 0; i < rocks.size(); ++i) {
            if(rocks[i] - prev < mid){
                count++;
            }
            else{
                prev = rocks[i];
            }
        }

        if(count > n){

            right = mid - 1;
        }
        else{
            answer = mid;
            left = mid + 1;
        }
    }


    return answer;
}


int main(){

    cout << solution(25, {2, 14, 11, 21, 17}, 2) << endl;

    return 0;
}