//
// Created by 이승민 on 2020-01-04.
//

#include <iostream>
#include <string>
#include <vector>
//#include <iterator>
//#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    //vector<int> answer1;
    //vector<int> answer2;
    //vector<string> user_id;
    //vector<string> name;
    unordered_map<string, string> user;
    vector <pair<string, int>> answer_;
    string k;
    for (int i = 0; i < record.size(); ++i) {

        vector <string> line;
        stringstream str(record[i]);
        while(str >> k){
            line.push_back(k);
        }

       /* if(i == 0){
            user_id.push_back(line[1]);
            name.push_back(line[2]);
            int size = user_id.size() - 1;
            answer1.push_back(size);
            answer2.push_back(0);
            continue;
        }
        else{
            vector<string>::iterator it;
            it = find(user_id.begin(), user_id.end(), line[1]);

            if(it == user_id.end()){
                user_id.push_back(line[1]);
                name.push_back(line[2]);
                int size = user_id.size() - 1;
                answer1.push_back(size);
                answer2.push_back(0);
            }
            else{
                int index = std::distance(user_id.begin(), it);
                if(line[0] == "Enter"){
                    name[index] = line[2];
                    answer1.push_back(index);
                    answer2.push_back(0);
                }
                else if(line[0] == "Leave"){
                    answer1.push_back(index);
                    answer2.push_back(1);
                }
                else{
                    name[index] = line[2];
                }
            }
        }*/

       if(line[0] == "Enter"){
           user[line[1]] = line[2];
           answer_.push_back(make_pair(line[1], 0));
       }
       else if(line[0] == "Leave"){
           answer_.push_back(make_pair(line[1], 1));
       }
       else{
            user[line[1]] = line[2];
       }
    }

    string status[2] = {"님이 들어왔습니다.", "님이 나갔습니다."};
    for (int i = 0; i < answer_.size(); ++i) {
        answer.push_back(user[answer_[i].first] + status[answer_[i].second]);
    }
    return answer;
}

int main(){

    vector <string>result = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
