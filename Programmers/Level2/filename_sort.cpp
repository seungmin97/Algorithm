//
// Created by 이승민 on 2020-01-19.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct name{
    string Head;
    int Number;
    string num;
    string Tail;
};

bool cmp(const name &a, const name &b){

    string a_head = a.Head;
    transform(a_head.begin(), a_head.end(), a_head.begin(), ::tolower);
    string a_tail = a.Tail;
    transform(a_tail.begin(), a_tail.end(), a_tail.begin(), ::tolower);

    string b_head = b.Head;
    transform(b_head.begin(), b_head.end(), b_head.begin(), ::tolower);
    string b_tail = b.Tail;
    transform(b_tail.begin(), b_tail.end(), b_tail.begin(), ::tolower);

    if(a_head < b_head){
        return true;
    }
    else if(a_head == b_head){
        if(a.Number < b.Number){
            return true;
        }
        else{
            return false;
        }
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
        string num = "";
        for (int j = index; j < files[i].length(); ++j) {
            if(isdigit(files[i][j])){
                index = j;
                break;
            }
            v[i].Head += files[i][j];
        }
        for (int j = index; j < files[i].length(); ++j) {
            if(!isdigit(files[i][j])){
                index = j;
                break;
            }
            v[i].num += files[i][j];
        }
        v[i].Number = stoi(v[i].num);

        for (int j = index; j < files[i].length(); ++j) {
            v[i].Tail += files[i][j];
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); ++i) {
        /*if(v[i].Tail == ""){
            answer.push_back(v[i].Head + v[i].num);
        }else{
            answer.push_back(v[i].Head + v[i].num + v[i].Tail);
        }*/
    }

    return answer;
}

int main(){

    vector <string> result;

    //result =  solution({"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
    //result.erase(result.begin(), result.end());
    //for (int i = 0; i < result.size(); ++i) {
    //    cout << result[i] << " ";
    //}
    //cout << endl;

    result = solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}