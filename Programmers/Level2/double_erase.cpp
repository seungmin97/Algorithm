//
// Created by 이승민 on 2020-01-28.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack <char> st;


    for (int i = 0; i < s.length(); ++i) {
        if(st.size() == 0){
            st.push(s[i]);
        }
        else{
            if(st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }

    if(st.size() == 0){
        answer = 1;
    }
    else{
        answer = 0;
    }

    return answer;
}

int main(){

    cout << solution("baabaa") << endl;
    cout << solution("cdcd");

    return 0;
}