//
// Created by 이승민 on 2019-09-12.
//

#include <iostream>
#include <vector>
using namespace std;

vector <int >v;
//FIFO

void print(){
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void pop(){

    if(v.size() != 0){
        //v.resize(v.size() - 1);
        v.erase(v.begin(), v.begin() + 1);
    }
    else{
        cout << "queue 사이즈가 0입니다.";
    }
    print();
}

void push(string str){
    int temp = stoi(str);
    //cout << temp;
    v.push_back(temp);

    print();
}
void size(){
    cout << v.size() << endl;
}
int main(){

    cout << "push 숫자" << endl;
    cout << "pop" << endl;
    cout << "size" << endl;
    cout << "quit" << endl;

    while(1){
        string str;
        getline(cin, str);

        if(str == "quit"){
            return 0;
        }
        else if(str == "pop"){
            pop();
        }
        else if(str == "size"){
            size();
        }
        else{
            string temp = str.substr(5, str.length() - 5);
            push(temp);

        }
    }

}