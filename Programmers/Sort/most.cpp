//
// Created by 이승민 on 2019-10-31.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &str1, const string &str2){
    int temp1 = stoi(str1+ str2);
    int temp2 = stoi(str2 + str1);

    if(temp1 > temp2){
        return true;
    }

    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector <string> temp;

    for (int i = 0; i < numbers.size(); ++i) {
        temp.push_back(to_string(numbers[i]));
    }

    sort(temp.begin(), temp.end(), cmp);

    for (int i = 0; i < temp.size(); ++i) {
        answer += temp[i];
    }
    if(answer[0] == '0'){
        answer =  '0';
    }
    return answer;
}

int main(){

    //vector <int> numbers = {6,10,2};
    //vector <int> numbers = {3,30,34,5,9};
    vector <int> numbers = {0, 0, 0,0};

    cout << solution(numbers);
    return 0;
}