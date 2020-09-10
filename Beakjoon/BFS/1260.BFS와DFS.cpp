//
// Created by 이승민 on 2020-09-10.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string dfs(vector<vector<int>> v, vector<bool> visit, int V){
    string result;

    result += to_string(V);
    visit[V] = true;

    for (int i = 0; i < v[V].size(); ++i) {
        if(!visit[v[V][i]]){

            result += dfs(v, visit, v[V][i]);
        }
    }

    return result;

}

int main(){

    int N, M, V;
    cin >> N >> M >> V;


    vector<vector<int>> v(N+1);

    vector<bool>visit(N+1, false);

    for (int i = 0; i < M; ++i) {
        //cout << "hello";
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }

    for (int i = 1; i <= N; ++i) {
        sort(v[i].begin(), v[i].end());
    }

    /*string result1 = to_string(V);
    visit[V] = true;
    result1 = dfs(v,visit, V);
    cout << result1 << endl;*/

    //DFS stack
    stack <int> s;
    s.push(V);
    visit[V] = true;
    vector<int> result1;
    result1.push_back(V);
    while(s.size() != 0){
        int node = s.top();
        s.pop();
        for (int i = 0; i < v[node].size(); ++i) {
            if(!visit[v[node][i]]){
                s.push(v[node][i]);
                visit[v[node][i]] = true;
                s.push(node);
                s.push(v[node][i]);
                result1.push_back(v[node][i]);
                break;
            }
        }
    }

    //DFS 재귀
/*    vector<int> result1;

    dfs(v, visit, V);
*/
    //memset(visit, false, sizeof(bool) * (N + 1));
    visit.assign(N, false);

    //BFS
    queue <int> q;
    q.push(V);
    visit[V] = true;
    vector <int> result2;
    while(q.size() != 0){
        int node = q.front();
        result2.push_back(node);

        for (int i = 0; i < v[node].size(); ++i) {
            if(!visit[v[node][i]]){
                q.push(v[node][i]);
                visit[v[node][i]] = true;
            }
        }

        q.pop();
    }

    for (int i = 0; i < N; ++i) {
        if(result1[i] == 0){
            break;
        }
        cout << result1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        if(result2[i] == 0){
            break;
        }
        cout << result2[i] << " ";
    }



    return 0;
}