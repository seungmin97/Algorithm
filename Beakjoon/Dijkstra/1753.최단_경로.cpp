//
// Created by 이승민 on 2020-02-28.
//

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int main(){

    //V는 정점의 갯수, E는 간선의 갯수, K는 시작 정
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> v(V + 1);

    for (int i = 0; i < E; ++i) {
        int temp1, temp2, score;
        cin >> temp1 >> temp2 >> score;
        v[temp1].push_back(make_pair(temp2, score));
    }

    int result[V + 1];
    memset(result, 0, sizeof(int) * (V + 1));
    int index = K;
    int next = 0;
    while(1){

        if(v[index].size() == 0){
            break;
        }

        for (int i = 0; i < v[index].size(); ++i) {

            if(result[v[index][i].first] != 0){
                result[v[index][i].first] = min(result[v[index][i].first], result[index] + v[index][i].second);
            }
            else{
                result[v[index][i].first] = result[index] + v[index][i].second;
            }

            if(i == 0){
                next = v[index][i].first;
            }
            else if(result[next] > result[v[index][i].first]){
                next = v[index][i].first;
            }
        }

        index = next;
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