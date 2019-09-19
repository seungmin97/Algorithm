//
// Created by 이승민 on 2019-09-18.
//

#include <iostream>

using namespace std;

int main(){

    int A, B, V;
    cin >> A >> B >> V;

    int location = 0;
   // int count = 0;
    int left = 0;
    int right = 1000000000;

    cout << A * 173184169 - B * (173184169 - 1);
    while(left <= right){
        int mid = (left + right) / 2;

        //낮위치
        location = (A * mid) - (B * (mid - 1));

        if((location < V + A) && (location >= V)){
            cout << mid;
            break;
        }
        else if(location >= V + A){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }

    }

    return 0;

}