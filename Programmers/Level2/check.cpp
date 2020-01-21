//
// Created by 이승민 on 2020-01-20.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct check{
    int a;
    int b;
    int c;
};

bool cmp(const check &c1, const check &c2){
    if(c1.a < c2.a){
        return true;
    }
    else if(c1.a == c2.a){
        if(c1.b == c2.b){
            return c1.c < c2.c;
        }
        return c1.b < c2.b;
    }
    else{
        return false;
    }
}

int main(){

    vector<check> v(100);

    v[0].a = 100;
    v[0].b = 1;
    v[0].c = 0;
    v[1].a = 100;
    v[1].b = 1;
    v[1].c = 1;
    for (int i = 2; i < 100; ++i) {
        v[i].a = rand() % 100;
        v[i].b = rand() % 100;
        v[i].c = i;
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); ++i) {
        cout  << v[i].a << " " << v[i].b <<" " <<v[i].c << endl;
    }
}