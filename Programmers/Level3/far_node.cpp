//
// Created by 이승민 on 2020-03-18.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    int count = 1;
    int *check = new int[n+1];
    memset(check, 0, sizeof(int) * (n + 1));

    queue <int> q;
    q.push(1);
    check[1] = 1;

    while(count < n){
        queue <int> q_;
        while(q.size() != 0){
            for (int i = 0; i < edge.size(); ++i) {
                if(edge[i][0] == q.front() && check[edge[i][1]] == 0){
                    check[edge[i][1]] = 1;
                    count++;
                    q_.push(edge[i][1]);
                }
                else if(edge[i][1] == q.front() && check[edge[i][0]] == 0){
                    check[edge[i][0]] = 1;
                    count++;
                    q_.push(edge[i][0]);
                }
            }
            q.pop();
        }
        answer = q_.size();
        q = q_;
    }

    /*
    for (int i = 0; i < edge.size(); ++i) {
        if(edge[i][0] > edge[i][1]){
            int temp;
            temp = edge[i][0];
            edge[i][0] = edge[i][1];
            edge[i][1] = temp;
        }
    }

    sort(edge.begin(), edge.end());

    int index = 0;
    queue<int> q;
    q.push(1);
    check[1] = 1;

    while(index < edge.size()){
        queue <int> q_;
        while(q.size() != 0){

            if(index == edge.size()){
                answer = q_.size();
                return answer;
            }

            if(edge[index][0] == q.front()){
                if(check[edge[index][1]] == 0){
                    q_.push(edge[index][1]);
                    check[edge[index][1]] = 1;
                }
                index++;
            }
            else{
                q.pop();
            }
        }

        answer = q_.size();
        q = q_;
    }
*/
    return answer;
}

int main(){

    cout << solution(6, {{3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2}});
}