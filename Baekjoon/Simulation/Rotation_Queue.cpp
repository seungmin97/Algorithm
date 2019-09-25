//
// Created by 이승민 on 2019-09-25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

int find(int temp){

    int count = 0;
    int index;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i] == temp){
            index = i;
            break;
        }
    }

    if(index <= v.size() / 2){
        for (int i = 0; i < index; ++i) {
            int back = v[0];
            v.push_back(back);
            v.erase(v.begin() + 0);
            count += 1;
        }
        v.erase(v.begin() + 0);
    }
    else{
        for (int i = 0; i < v.size() - index; ++i) {
            int front = v.back();
            v.pop_back();
            v.insert(v.begin() + 0, front);
            count += 1;
        }
        v.erase(v.begin() + 0);
    }

    return count;
}

int main() {

    int N, M;
    cin >> N >> M;

    int arr[50];
    for (int i = 0; i < M; ++i) {
        cin >> arr[i];
    }


    for (int i = 0; i < N; ++i) {
        v.push_back(i + 1);
    }

    int result = 0;
    for (int i = 0; i < M; ++i) {
        result += find(arr[i]);
    }

    cout << result;
    return 0;
}