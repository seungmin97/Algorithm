//
// Created by 이승민 on 2019-09-10.
//

#include <iostream>

using namespace std;

int main(){

    int N, K;
    cin >> N >> K;

    int *arr = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = N - 1; i >= 0 ; --i) {
        int temp = (K / arr[i]);
        result += temp;
        if(temp != 0){
            K -= temp * arr[i];
        }
        if(K == 0){
            break;
        }
    }

    cout << result;
    return 0;
}
