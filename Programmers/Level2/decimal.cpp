//
// Created by 이승민 on 2020-03-25.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

bool check1(int n, int *arr){

    string temp = to_string(n);
    int *arr_  = new int[10];
    memcpy(arr_, arr, sizeof(int) * 10);


    for (int i = 0; i < temp.length(); ++i) {

        int index = temp[i] - '0';
        if(arr_[index] > 0){
            arr_[index] -= 1;
        }
        else{
            return 0;
        }
    }
    return 1;
}


bool check2(int n){

    int i = 0;
    int last = n / 2;   //약수가 없는 수가 소수이므로 2부터 n/2(자기자신/2)까지만 확인하면 됨
    if (n <= 1)//소수는 1보다 큰 자연수여야 함
    {
        return 0;
    }
    //(자기자신/2)보다 큰수는 약수가 될 수 없음
    for (i = 2; i <= last; i++) //i를 2부터 last까지 1씩 증가시키며 반복 수행
    {
        if ((n%i) == 0) //n을 i로 나누었을때 나머지가 0이면(즉, i는 n의 약수가 아님)
        {
            return 0; //소수가 아니므로 0반환(i가 약수이므로 n은 소수가 아님)
        }
    }

    return 1;
}

int solution(string numbers) {
    int answer = 0;

    vector<int> v;
    int *arr = new int[10];
    memset(arr, 0, sizeof(int) * 10);

    for (int i = 0; i < numbers.length(); ++i) {
        arr[numbers[i] - '0']++;
        v.push_back(numbers[i] - '0');
    }

    string temp;
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); ++i) {
        temp += to_string(v[i]);
    }

    for (int i = 2; i <= atoi(temp.c_str()); ++i) {

        if(!check1(i, arr)){
            continue;
        }

        if(check2(i)){
                answer++;
        }
        else{
            continue;
        }
    }

    return answer;
}

int main(){

    cout << solution("17") << endl;
    cout << solution("011") << endl;

    return 0;
}