//
// Created by 이승민 on 2019-10-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 0;
    vector <string> num;
    vector <string>::iterator it;
    vector <vector<string>> v;

    for (int i = 0; i < clothes.size(); ++i) {
        it = find(num.begin(), num.end(), clothes[i][1]);
        if(it == num.end()){
            num.push_back(clothes[i][1]);

            v[num.size() - 1].push_back(clothes[i][0]);
        }
        else{
            int index = it - v.begin();
            v[index].push_back(clothes[i][0]);
        }
    }


    cout << v.size();

    return answer;
}

int main(){

    vector <vector<string>> clothes;

    vector <string> temp;

    temp.push_back("yelloww_hat");
    temp.push_back("headgear");
    clothes.push_back(temp);
    temp.clear();

    temp.push_back("blue_sunglasses");
    temp.push_back("eyewear");
    clothes.push_back(temp);
    temp.clear();

    temp.push_back("green_turban");
    temp.push_back("headgear");
    clothes.push_back(temp);
    temp.clear();

    /*
    temp.push_back("crow_mask");
    temp.push_back("face");
    clothes.push_back(temp);
    temp.clear();

    temp.push_back("blue_sunglasses");
    temp.push_back("face");
    clothes.push_back(temp);
    temp.clear();

    temp.push_back("smoky_makeup");
    temp.push_back("face");
    clothes.push_back(temp);
    temp.clear();*/

    solution(clothes);

    return 0;
}