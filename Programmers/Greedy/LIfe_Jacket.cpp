//
// Created by 이승민 on 2019-11-14.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<int>());

    int index = 1;
    int num = 0;
    for (int i = 0; i < people.size(); ++i) {

        if(i >= people.size() - index){
            answer += 1 ;
            return answer;
        }

        if(people[i] + people[people.size() - index] <= limit){
            num += 2;
            answer += 1;
            index += 1;
        }
        else{
            num += 1;
            answer += 1;
        }

        if(num == people.size()){
            return answer;
        }
    }
}

int main(){

    //vector <int> people = {70, 50, 80, 50};
    //int limit = 100;

    vector <int> people = {70, 80, 50};
    int limit = 100;

    cout << solution(people, limit);
    return 0;
}
