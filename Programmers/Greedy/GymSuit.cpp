//
// Created by 이승민 on 2019-11-19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector <int> check(n);

    sort(lost.begin(), lost.end());

    int index = 0;
    for (int i = 0; i < n; ++i) {
        if(i == (lost[index] - 1)){
            check[i] = 0;
            index++;
        }
        else{
            check[i] = 1;
        }
    }

    answer += (n - lost.size());

    for (int i = 0; i < reserve.size(); ++i) {
        index = reserve[i] - 1;

        if(index > 0 && index < n - 1){
            if(check[index - 1] == 0){
                check[index - 1] = 1;
                answer += 1;
                continue;
            }
            else if(check[index + 1] == 0){
                check[index + 1] = 1;
                answer += 1;
                continue;
            }
        }
        else if(index == 0){
            if(check[index + 1] == 0){
                check[index + 1] = 1;
                answer += 1;
                continue;
            }
        }
        else if(index == n - 1){
            if(check[index - 1] == 0){
                check[index - 1] = 1;
                answer += 1;
                continue;
            }
        }
    }

    return answer;
}

int main(){

    /*int n = 5;
    vector <int> lost = {2, 4};
    vector <int> reserve = {1, 3, 5};*/

    /*int n = 5;
    vector <int> lost = {2, 4};
    vector <int> reserve = {3};*/

    int n = 3;
    vector <int> lost = {3};
    vector <int> reserve = {1};

    cout << solution(n, lost, reserve);

    return 0;
}