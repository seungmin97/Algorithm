//
// Created by 이승민 on 2020-03-30.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct city{
    string name;
    vector<string> des;
};

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    vector<city> temp;
    int index = 0;
    int check = 0;

    for (int i = 0; i < tickets.size(); ++i) {
        check = -1;
        for (int j = 0; j < temp.size(); ++j) {
            if(temp[j].name == tickets[i][0]){
                check = j;
                break;
            }
        }

        if(check == -1){
            city c;
            c.name = tickets[i][0];
            c.des.push_back(tickets[i][1]);
            if(c.name == "ICN"){
                index = temp.size();
            }
            temp.push_back(c);
        }
        else{
            temp[check].des.push_back(tickets[i][1]);
            sort(temp[check].des.begin(), temp[check].des.end());
        }
    }

    answer.push_back("ICN");

    while(1){
        check = 0;
        string destination = temp[index].des[0];
        temp[index].des.erase(temp[index].des.begin());

        if(destination == ""){
            break;
        }

        answer.push_back(destination);

        for (int i = 0; i < temp.size(); ++i) {
            if(temp[i].name == destination){
                index = i;
                check = 1;
                if(temp[i].des.size() == 0){
                    return answer;
                }
                break;
            }

        }
        if(check == 0){
            return answer;
        }
    }

    return answer;
}

int main(){


    vector<string> temp;
    /*temp = solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i] << " ";
    }
    cout << endl;*/

    temp.erase(temp.begin(), temp.end());
    temp = solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}});
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i] << " ";
    }
    cout << endl;
}