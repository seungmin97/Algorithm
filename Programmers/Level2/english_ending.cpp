//
// Created by 이승민 on 2020-01-06.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    vector<string> storage;
    storage.push_back(words[0]);
    string temp = words[0];

    vector<string>::iterator it;
    for (int i = 1; i < words.size(); ++i) {

        if(words[i][0] != temp[temp.length() - 1]){
            answer.push_back((i % n) + 1);
            answer.push_back(i/ n + 1);
            return answer;
        }

        it = find(storage.begin(), storage.end(), words[i]);
        if(it != storage.end()){

            answer.push_back((i % n) + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        temp = words[i];
        storage.push_back(words[i]);
    }

    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

int main(){

    vector<int> result;

    result = solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
    cout << result[0] << " " << result[1] << endl;

    result = solution(5, {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"});
    cout << result[0] << " " << result[1] << endl;

    result = solution(2, {"hello", "one", "even", "never", "now", "world", "draw"});
    cout << result[0] << " " << result[1] << endl;

    return 0;

}