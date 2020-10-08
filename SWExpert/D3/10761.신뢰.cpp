#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(string str){

    int result = 0;

    priority_queue<int, vector<int>, greater<int>> O;
    priority_queue<int, vector<int>, greater<int>> B;

    for (int i = 2; i < str.length(); ++i) {

        if(str[i] == 'O'){
            O.push(str[i+2] - 48);
            i+=3;
        }
        else if(str[i] == 'B'){
            B.push(str[i+2] - 48);
            i+=3;
        }
    }

    int O_index = 0, B_index = 0;
    while(O.size() != 0 && B.size() != 0){
        if(O[O_index] < B[B_index]){

        }
        else if(O[O_index] > B[B_index]){

        }
        else{

        }
    }


    return result;
}

int main(){

    int TC;
    cin >> TC;

    vector<string> v;
    vector<int> answer;

    string str;
    getline(cin,str);

    for (int i = 0; i < TC; ++i) {
        getline(cin, str);
        v.push_back(str);
    }

    for (int i = 0; i < TC; ++i) {
        answer.push_back(solution(v[i]));
    }

    return 0;
}