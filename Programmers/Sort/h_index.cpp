//
// Created by 이승민 on 2019-11-01.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int num = 0;
    while(num <= citations[citations.size() - 1]){
        int big = 0;
        int small = 0;

        for (int i = 0; i < citations.size(); ++i) {
            if(citations[i] >= num){
                big++;
            }
            else if(citations[i] < num){
               small++;
            }
        }

        if(big + small == citations.size() && big >= num){
            answer = max(answer, num);
        }
        num++;
    }

    return answer;
}

int main(){

    vector <int> citations = {3, 0, 6, 1, 5};

    cout << solution(citations);

    return 0;
}