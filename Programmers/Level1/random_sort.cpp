//
// Created by 이승민 on 2019-12-24.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int temp;

bool cmp(const string &str1, const string &str2){
    if(str1[temp] == str2[temp]){
        return str1 < str2;
    }
    else if(str1[temp] < str2[temp]){
        return str1 > str2;
    }
    else{
        return str2 > str1;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    temp = n;
    sort(strings.begin(), strings.end());

    sort(strings.begin(), strings.end(), cmp);


    return strings;
}

int main(){
    vector <string> result;

    result = solution({"sun", "bed", "car"}, 1);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    result.erase(result.begin(), result.end());

    cout << endl;
    result = solution({"abce", "abcd","abcc", "cdx"}, 2);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}