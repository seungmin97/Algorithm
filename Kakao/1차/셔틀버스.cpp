//
// Created by 이승민 on 2019-10-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    /*int n = 1, t = 1, m = 5;
    string str[4] = {"08:00", "08:01", "08:02", "08:03"};*/

    /*int n = 2, t = 10, m = 2;
    string str[3] = {"09:10", "09:09", "08:00"};*/

    /*int n = 2, t = 1, m = 2;
    string str[4] = {"09:00", "09:00", "09:00", "09:00"};*/

    /*int n = 1, t = 1, m = 5;
    string str[5] = {"00:01", "00:01", "00:01", "00:01", "00:01" };*/

    /*int n = 1, t = 1, m = 1;
    string str[1] = {"23:59"};*/

    int n = 10, t = 60, m = 45;
    string str[16] = {"23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"
            , "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};

    int size  = sizeof(str) / sizeof(string);

    vector <pair<int, int>> v;
    for (int i = 0; i < size; ++i) {
        int hour = stoi(str[i].substr(0, 2));
        int minute = stoi(str[i].substr(3,5));
        v.push_back(make_pair(hour,minute));
    }

    sort(str, str + size);
    sort(v.begin(), v.end());


    int start_hour = 9;
    int start_minute = 0;

    int hour, minute;

    for (int i = 0; i < n; ++i) {

        int people = 0;

        for (int j = 0; j < v.size(); ++j) {
            if(start_hour == v[j].first && start_minute >= v[j].second){
                people += 1;
            }
            else if(start_hour > v[j].first){
                people += 1;
            }
            else {
                break;
            }
        }

        if(i == (n - 1)){
            if(people >= m){

                minute = v[m - 1].second - 1;
                hour = v[m - 1].first;

                if(minute < 0){
                    minute += 60;
                    hour -= 1;
                }
            }
            else{
                minute = start_minute;
                hour = start_hour;
            }
        }
        else{
            if(people > m){
                v.erase(v.begin(), v.begin() + m);
            }
            else{
                v.erase(v.begin(), v.begin() + people);
            }
        }

        start_minute += t;

        if(start_minute >= 60){
            start_minute -= 60;
            start_hour += 1;
        }
    }


    cout << hour << ":" << minute;

    return 0;
}

