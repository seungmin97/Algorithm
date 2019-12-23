//
// Created by 이승민 on 2019-12-19.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    return arr;
}

int main(){

    vector <int> result;
    result = solution({1,1,3,3,0,1,1});

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
    }

    return 0;
}