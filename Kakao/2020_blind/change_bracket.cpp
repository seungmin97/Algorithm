//
// Created by 이승민 on 2020-01-13.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int check(string s){
    stack <char> ss;

    if(s[0] == ')'){
        return 0;
    }

    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '('){
            ss.push(s[i]);
        }
        else{

            if(ss.size() == 0){
                return 0;
            }

            if(ss.top() == '('){
                ss.pop();
            }
            else{
                return 0;
            }
        }
    }
    if(ss.size() == 0){
        return 1;
    }
    else{
        return 0;
    }
}


string solution(string p) {
    string answer = "";
    int index = 0;
    stack <string> st;
    string temp;

    if(check(p)){
        return p;
    }

    while(index < p.length()){
        int left = 0;
        int right = 0;
        temp = "";

        for (int i = index; i < p.length(); ++i) {

            if(p[i] == '('){
                temp += '(';
                left++;
            }
            else{
                temp += ')';
                right++;
            }

            if(left == right){
                left = 0;
                right = 0;
                st.push(temp);
                temp = "";
                index = i+1;
                continue;
            }
        }
    }

    temp = "";

    if(check(st.top())){
        temp = st.top();
        st.pop();
    }

   while(st.size() != 0) {

        string u = st.top();
        st.pop();
        //올바른 문자열
        if(check(u)){
            temp.insert(0, u);
            //st.pop();
        }
        else{

            temp.insert(0, "(");
            temp += ")";
            for (int j = 1; j < u.size()-1; ++j) {
                if(u[j] == '('){
                    temp += ')';
                }
                else{
                    temp += '(';
                }
            }
        }

    }
99 jm
   answer = temp;
    return answer;
}

int main(){

    cout << solution("(()())()") << endl;
    cout << solution(")(") << endl;
    cout << solution("()))((()") << endl;
    cout << solution(")()()()(");
}