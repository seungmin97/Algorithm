//
// Created by 이승민 on 2020-02-05.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    vector<int> temp;
    int *check = new int[B.size()];
    memset(check, 0, sizeof(int) * B.size());

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int index = 0;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = index; j < B.size(); ++j) {
            if(B[j] - A[i] > 0){
                index = j + 1;
                answer++;
                break;
            }
        }
    }


   /* for (int i = 0; i < A.size(); ++i) {
       vector <pair<int,int>> p;
        for (int j = 0; j < B.size(); ++j) {
            int minus = B[j] - A[i];
            if(minus > 0 && check[j] == 0){
                p.push_back(make_pair(minus, j));
            }
        }
        sort(p.begin(), p.end());
        if(p.size() != 0){
            temp.push_back(p[0].second);
            check[p[0].second] = 1;
        }
        else{
            temp.push_back(-1);
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        if(temp[i] != -1){
            answer++;
        }
    }*/

    return answer;
}

int main(){

    cout << solution({5,1,3,7}, {2,2,6,8}) << endl;
    cout << solution({2,2,2,2}, {1,1,1,1}) << endl;

    return 0;
}