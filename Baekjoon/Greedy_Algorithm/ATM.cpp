//
// Created by 이승민 on 2019-09-10.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    int *arr = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += arr[i] * (N - i);
    }

    cout << sum;
    return 0;
}