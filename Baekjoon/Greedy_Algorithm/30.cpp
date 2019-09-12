//
// Created by 이승민 on 2019-09-11.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

bool cmp(int &a, int &b){
    if(a > b){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    string str;
    cin >> str;

    int sum = 0;
    int check = 0;

    int *arr = new int[str.length()];
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] == '0'){
            check = 1;
        }
        //cout << (int)str[i] - 48
        int num = (int)str[i] - 48;
        arr[i] = num;
        sum += num;

    }

    if((sum % 3 == 0) && (check == 1)){
        sort(arr, arr + str.length(), cmp);
    }
    else{
        cout << -1;
        return 0;
    }

    for (int i = 0; i < str.length(); ++i) {
        cout << arr[i];
    }

    return 0;
}