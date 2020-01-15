//
// Created by 이승민 on 2020-01-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());

    if(temp.size() >= (nums.size() / 2)){
        return nums.size() / 2;
    }
    else{
        return temp.size();
    }

}

int main(){

    cout << solution({3,1,2,3}) << endl;
    cout << solution({3,3,3,2,2,4}) << endl;
    cout << solution({3,3,3,2,2,2});

    return 0;
}