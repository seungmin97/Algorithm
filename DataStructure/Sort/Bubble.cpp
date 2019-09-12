//
// Created by 이승민 on 2019-09-12.
//

#include <iostream>

using namespace std;

void print(int *arr){
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){

    int arr[6] = {4, 2, 9, 6, 5, 10};

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5 - i; ++j) {
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

            print(arr);
        }
    }
    return 0;
}