//
// Created by 이승민 on 2020-02-28.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

struct path{
    int start;
    int end;
    int score;
};

int main(){

    //V는 정점의 갯수, E는 간선의 갯수, K는 시작 정
    int V, E, K;
    cin >> V >> E >> K;

    vector<path> v(V + 1);
    for (int i = 0; i < E; ++i) {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;

        path p;
        p.start = temp1;
        p.end = temp2;
        p.score = temp3;

        v.push_back(p);
    }

    queue<int> q;
    q.push(K);
    int result[V + 1];
    memset(result, 0, sizeof(int) * (V + 1));

    while(q.size() != 0){

        int index = q.front();

        int size = v.size();
        for (int i = 0; i < size; ++i) {
            if(v[i].start == index){
                q.push(v[i].end);
                if(result[v[i].end] == 0){
                    result[v[i].end] = result[index] + v[i].score;
                }
                else{
                    result[v[i].end] = min(result[index] + v[i].score, result[v[i].end]);
                }
            }
            v.erase(v.begin() + i);
        }

        q.pop();

    }

    for (int i = 1; i <= V; ++i) {
        if(i == K){
            cout << 0 << endl;
        }
        else if(result[i] == 0){
            cout << "INF" << endl;
        }
        else{
            cout << result[i] << endl;
        }
    }

    return 0;
}