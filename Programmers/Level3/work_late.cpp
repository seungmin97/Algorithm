//
// Created by 이승민 on 2020-01-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue <int> pq;

    for (int i = 0; i < works.size(); ++i) {
        pq.push(works[i]);
    }

    int temp;
    for (int i = 0; i < n; ++i) {

        if(pq.top() != 0){
            temp = pq.top() - 1;
            pq.pop();
            pq.push(temp);
        }
        else{
            answer = 0;
            return answer;
        }
    }

    while(pq.size() != 0){
        temp = pq.top();
        pq.pop();
        if(temp == 0){
            return answer;
        }
        answer += temp*temp;
    }

    return answer;
}

int main(){

    cout << solution(4, {4,3,3}) << endl;
    cout << solution(1, {2,1,2}) << endl;
    cout << solution(3, {1,1});
}