//
// Created by 이승민 on 2019-09-19.
//

#include <iostream>
#include <algorithm>
#define Max 1000000

using namespace std;

long long cut(int mid, int *arr, int N){
    long long length = 0;

    for (int i = 0; i < N; ++i) {
        int temp = arr[i] - mid;
        if(temp > 0){
            length += temp;
        }
    }
    return length;
}

int main(){

    int max_ = 0;
    int min_ = Max;

    int arr[Max];
    int N;
    long long M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];

        max_ = max(max_, arr[i]);
        //min_ = min(min_, arr[i]);
    }

    int left = 0;
    int right = max_;
    int result = 0;

    while(left <= right){
        int mid = (left + right) / 2;

        long long tree = cut(mid, arr, N);

        if(tree >= M){
            result = max(result, mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }


    cout << result;
    return 0;
}