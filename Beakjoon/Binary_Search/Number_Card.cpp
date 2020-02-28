//
// Created by 이승민 on 2019-09-18.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define Max 500000

int result[Max];
void find(int i, int temp, int *arr, int left, int right){

    while(left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > temp)
            right = mid - 1;
        else if (arr[mid] < temp)
            left = mid + 1;
        else {
            result[i] = 1;
            break;
        }
    }
}



int main(){

    int arr1[Max];
    int arr2[Max];

    int N, M;

    memset(result, 0, Max);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr1[i];
    }
    sort(arr1, arr1 + N);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> arr2[i];
    }
    //sort(arr2, arr2 + M);

    for (int i = 0; i < M; ++i) {
        find(i, arr2[i], arr1, 0, N);
        cout << result[i] << " ";
    }

    return 0;
}