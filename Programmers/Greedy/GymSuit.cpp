//
// Created by 이승민 on 2019-11-19.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    int answer = 0;
    int *check = new int[n + 2];
    memset(check, 0, sizeof(int) * (n + 2));

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    //옷을 잃어버린게 아니면 체육복을 입을 수 있음
    answer += n - lost.size();

    //옷을 잃어버렸으면 -1 옷의 여분을 가지고 있으면 1 아니면 0
    int index1 = 0;
    int index2 = 0;
    for (int i = 1; i <= n; ++i) {
        if(i == lost[index1]){
            check[i] = -1;
            index1++;
        }
        if(i == reserve[index2]){
            //옷을 잃어버렸는데 여분이 있는 경
            if(check[i] == -1){
                check[i] = 0;
                answer += 1;
            }
            else{
                check[i] = 1;
            }
            index2++;
        }
    }

    //먼저 오른쪽으로 빌려줄것인지 왼쪽으로 빌려줄 것인지 확인
    int check1[n+2];
    copy(check, check + n + 2, check1);
    int count1 = 0;
    for (int i = 1; i < n; ++i) {
        if(check1[i] == 1 && check1[i + 1] == -1){
            count1++;
            check1[i] = 0;
            check1[i + 1] = 0;
            i++;
        }
    }
    int check2[n+2];
    copy(check, check + n + 2, check2);
    int count2 = 0;
    for (int i = n; i > 0; --i) {
        if(check2[i] == 1 && check2[i - 1] == -1){
            count2++;
            check2[i] = 0;
            check2[i - 1] = 0;
        }
    }

    //반대로 빌려주는 경우
    if(count1 > count2){
        answer += count1;
        for (int i = n; i > 0; --i) {
            if(check1[i] == 1 && check1[i - 1] == -1){
                answer += 1;
                i--;
            }
        }
    }
    else{
        answer += count2;
        for (int i = 0; i < n; ++i) {
            if(check2[i] == 1 && check2[i + 1] == -1){
                answer++;
                i++;
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

    /*int n = 3;
    vector <int> lost = {3};
    vector <int> reserve = {1};*/

    int n = 5;
    vector <int> lost = {2, 4};
    vector <int> reserve = {3, 5};

    /*
     * n = 9
lost = {2,4,7,8 }
reserve = {3,6,9}
answer = 8

n = 5
lost = {2,4}
reserve = {3,5}
answer = 5*/
    cout << solution(n, lost, reserve);

    return 0;
}