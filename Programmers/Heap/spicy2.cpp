//
// Created by 이승민 on 2020-01-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue <int,vector<int>,greater<int>> pq;
    for (int i = 0; i < scoville.size(); ++i) {
        pq.push(scoville[i]);
    }

    while(pq.top() < K && pq.size() >= 2){
        int var1 = pq.top();
        pq.pop();
        int var2 = pq.top();
        pq.pop();
        int temp = var1 + var2 *2;
        pq.push(temp);
        answer++;
    }

    if(answer == scoville.size() - 1 && pq.top() < K){
        return -1;
    }

    return answer;
}

int main(){

    cout << solution({1, 2, 3}, 11);

    return 0;
}