#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    int *result = new int[T];
    memset(result, 0, sizeof(int) * T);

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int length;
        string str1, str2;
        cin >> length >> str1 >> str2;

        for (int j = 0; j < str1.length(); ++j) {
            if(str1[j] == str2[j]){
                result[test_case-1]++;
            }
        }
    }
    for (int i = 0; i < T; ++i) {
        cout << "#" << i + 1 << " " << result[i] << endl;
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}