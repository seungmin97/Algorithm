//
// Created by 이승민 on 2019-10-10.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> divide(string str){

    vector <string> v;
    for (int i = 0; i < str.length(); ++i) {

        if((str[i] >= 65) && (str[i] <= 90)){
            if((str[i + 1] >= 65) &&(str[i + 1] <= 90)){
                cout << str.substr(i,2) << " ";
                v.push_back(str.substr(i, 2));
            }
        }
    }

    return v;
}

int main() {

    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";

    //, , , , , , ,
    transform(str1.begin(), str1.end(), str1.begin(),  (int(*)(int))toupper);
    transform(str2.begin(), str2.end(), str2.begin(),  (int(*)(int))toupper);

    vector <string> v1;
    vector <string> v2;

    v1 = divide(str1);
    cout << endl;
    v2 = divide(str2);

    //int u = v1.size() + v2.size();
    int count = 0;

    for (int i = 0; i < v2.size(); ++i) {
        vector <string>::iterator it;

        it = find(v1.begin(), v1.end(), v2[i]);

        if(it != v1.end()) {
            count += 1;
            //u -= 1;
            v1.erase(it);
            //v2.erase(v2.begin() + i);
        }
    }

    if(v1.size() + v2.size() == 0){
        cout << "65536";
        return 0;
    }


    int result = 65536 * count / ( + v1.size() + v2.size());
    cout << result;



    return 0;
}