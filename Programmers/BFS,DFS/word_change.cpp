//
// Created by 이승민 on 2020-10-23.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<bool> check(50,false);
queue<string> q;

int bfs(string target, vector<string> words){

    int count = -1;

    while(1){
        count++;
        queue<string> q_;
        while(q.size()!= 0){
            string temp = q.front();

            if(temp == target){
                return count;
            }


            for( int i = 0; i <words.size(); i++){
                int same = 0;

                if(check[i]){
                    continue;
                }

                for(int j = 0; j < words[i].size(); j++){
                    if(temp[j] == words[i][j]){
                        same++;
                    }
                }

                if(same == temp.length() - 1){
                    check[i] = true;
                    q_.push(words[i]);
                }
            }
            q.pop();
        }
        q = q_;
    }
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<string>::iterator it;
    it = find(words.begin(), words.end(), target);

    //단어를 변환할 수 없는 경우
    if(it == words.end()){
        return 0;
    }
    else{
        q.push(begin);
        answer = bfs(target, words);
    }



    return answer;
}