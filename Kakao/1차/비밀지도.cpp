//
// Created by 이승민 on 2019-10-07.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

void dec_to_bin(int temp, int *map1){

    vector <int> v;

    for (int j = 0; j < N; ++j) {
        int result = temp % 2;
        v.push_back(result);
        temp /= 2;
    }

    for (int i = 0; i < N; ++i) {
        map1[i] = v[N - 1 - i];
        cout << map1[i]  << " ";
    }
    cout << "   ";
}

void result(int *map1, int *map2, int *map){
    for (int i = 0; i < N; ++i) {
        if(map1[i] == 0 && map2[i] == 0){
            map[i] =  0;
        }
        else{
            map[i] = 1;
        }
        cout << map[i] << " ";

    }
    cout << "   ";
}

int main(){

    /*
    N = 6;
    int arr1[6] = {46, 33, 33 ,22, 31, 50};
    int arr2[6] = {27 ,56, 19, 14, 14, 10};
     */

    N = 5;
    int arr1[5] = {9, 20, 28, 18, 11};
    int arr2[5] = {30, 1, 21, 17, 28};

    int map[N][N];
    int map1[N][N];
    int map2[N][N];
    for (int i = 0; i < N; ++i) {
        memset(map1[i], 0, sizeof(int) * N);
        memset(map2[i], 0, sizeof(int)  * N);
        memset(map[i], 0, sizeof(int) * N);

        dec_to_bin(arr1[i], map1[i]);
        dec_to_bin(arr2[i], map2[i]);

        result(map1[i], map2[i], map[i]);
        cout << endl;
    }

    return 0;
}
