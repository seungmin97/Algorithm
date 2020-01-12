#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	answer += toupper(s[0]);
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] == ' ') {
			answer += toupper(s[i]);
		}
		else {
			answer += s[i];
		}
	}


	return answer;
}

int main() {

	cout << solution("3people unFollowed me");

	return 0;
}