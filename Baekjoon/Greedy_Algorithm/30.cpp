//
// Created by 이승민 on 2019-09-11.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>

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

    int *check = new int[10];
    memset(check, 0);

    string str;
    cin >> str;

    int *arr = new int[str.length()];
    for (int i = 0; i < str.length(); ++i) {
        check[int(str[i]) - 48] += 1;
        arr[i] = int(str[i]) - 48;
    }

    sort(arr, arr + str.length(), cmp);

    int temp = 0;

    for (int i = 0; i < str.length() ; ++i) {
        temp += arr[i] * pow(10, (str.length() - i - 1));
    }

    cout << temp;

    int num = (temp / 30) * 30;

    for (int i = num; i >= 0 ; i-=30) {
        int *check_ = new int[10];
        check_ = check;

        for (int j = str.length() - 1; j >= 0; --j) {

        }

    }

    return 0;
}