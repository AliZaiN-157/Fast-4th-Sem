#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string StringExpression(string str) {
	string result = "";
	vector<string> numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> operators = { "plus", "minus" };
	vector<string> strVec;
	string temp = "";
	int num = 0;
	int total = 0;
	bool negative = false;
	for (int i = 0; i < str.length(); i++) {
		temp += str[i];
		if (find(numbers.begin(), numbers.end(), temp) != numbers.end()) {
			strVec.push_back(temp);
			temp = "";
		}
		else if (find(operators.begin(), operators.end(), temp) != operators.end()) {
			strVec.push_back(temp);
			temp = "";
		}
	}
	for (int i = 0; i < strVec.size(); i++) {
		if (find(numbers.begin(), numbers.end(), strVec[i]) != numbers.end()) {
			num = find(numbers.begin(), numbers.end(), strVec[i]) - numbers.begin();
			if (i == 0) {
				total += num;
			}
			else if (strVec[i - 1] == "plus") {
				total += num;
			}
			else if (strVec[i - 1] == "minus") {
				total -= num;
			}
		}
	}
	if (total < 0) {
		negative = true;
		total *= -1;
	}
	while (total > 0) {
		result = numbers[total % 10] + result;
		total /= 10;
	}
	if (negative) {
		result = "negative" + result;
	}
	return result;
}

int main() {
	cout << StringExpression("oneminuseight") << endl;
	return 0;
}