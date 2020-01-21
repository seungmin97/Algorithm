//
// Created by 이승민 on 2020-01-19.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct name{
    string original;
    string Head;
    int num;
    int idx;
};

bool cmp(const name &a, const name &b){

    if(a.Head < b.Head){
        return true;
    }
    else if(a.Head == b.Head){
        if(a.num == b.num){
            return a.idx < b.idx;
        }
        return a.num < b.num;
    }
    else{
        return false;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<name> v(files.size());

    for (int i = 0; i < files.size(); ++i) {
        int index = 0;

        v[i].original = files[i];

        //head구하기
        for (int j = index; j < files[i].length(); ++j) {
            if(isdigit(files[i][j])){
                index = j;
                break;
            }
            v[i].Head += tolower(files[i][j]);
        }

        //num구하기
        string temp;
        for (int j = index; j < files[i].length(); ++j) {
            if(!isdigit(files[i][j])){
                break;
            }
            temp += files[i][j];
        }
        v[i].num = stoi(temp);
        v[i].idx = i;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); ++i) {
        answer.push_back(v[i].original);
    }

    return answer;
}

int main(){

    vector <string> result;

    result =  solution({"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    result.erase(result.begin(), result.end());

    //result = solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});
    //for (int i = 0; i < result.size(); ++i) {
    //    cout << result[i] << " ";
    //}

    return 0;
}