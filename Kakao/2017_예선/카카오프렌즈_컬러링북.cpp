//
// Created by 이승민 on 2019-10-22.
//

#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> v;

int check(int temp, int i, int j, int m, int n){

    if (i >= m || j >= n || i < 0 || j < 0 || temp != v[i][j])
        return 0;

    v[i][j] = 0;

    int area = 1;

    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};

    for (int k = 0; k < 4; ++k) {
        area += check(temp, i + x[k], j + y[k], m, n);
    }

    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    v = picture;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            if(v[i][j] == 0){
                continue;
            }

            int result = check(picture[i][j], i, j, m, n);
            max_size_of_one_area = max(max_size_of_one_area, result);
            number_of_area += 1;
        }

    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(){

    vector <vector <int>> picture(5);

    picture[0] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 1};
    picture[1] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 1};
    picture[2] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    picture[3] = {1, 1, 1, 2, 1, 1, 1, 1, 2, 1};
    picture[4] = {1, 1, 2, 1, 2, 1, 1, 2, 1, 2};
    //picture[5] = {0,0,0,1};

    vector <int> result;
    result = solution(5, 10, picture);

    cout << result[0] << " " << result[1];

    return 0;
}