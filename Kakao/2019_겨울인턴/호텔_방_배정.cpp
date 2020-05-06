//
// Created by 이승민 on 2020-05-06.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<long long, long long> m;

long long find(long long index){

    if(m[index] == 0){
        return index;
    }

    return m[index] = find(m[index]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;


        for(long long room : room_number){
            if(m[room] == 0){
                answer.push_back(room);
                m[room] = room + 1;
            }
            else{
                long long temp = find(room);
                answer.push_back(temp);
                m[temp] = find(temp + 1);
            }
        }



    return answer;
}

int main(){

    vector<long long> result = solution(10, {1,3,4,1,3,1});

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}