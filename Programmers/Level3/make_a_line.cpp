//
// Created by 이승민 on 2020-03-23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial(int n){
    if(n<=1) return 1;
    else return n*factorial(n-1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;

    vector<int>temp;
    for (int i = 0; i < n; ++i) {
        temp.push_back(i + 1);
    }

    while(1){

       int num = factorial(temp.size() - 1);
       int index = (k - 1) / num;

       answer.push_back(temp[index]);
       temp.erase(temp.begin() + index);
       
       k -= (num * index);

       if(temp.size() == 1){
           answer.push_back(temp[0]);
           break;
       }
    }

    return answer;
}

int main(){

    vector<int>v;
    v = solution(3, 5);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }

}