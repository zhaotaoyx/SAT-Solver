//This is a function that convert a string which contains integers seperated by empty space to integers.
//If there is any character which is not a integer digit, then return an empty vector.
//For the purpose of this problem, 0 will not count as a valid integer.
#include <vector>
#include <string>
#include "additional_functions.h"

using namespace std;

vector<int> StringToIntegers(string s) {
	vector<int> integers;
	int curint = 0;
	bool positive = true;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != ' ' && s[i] != '-' && (s[i] < '0' || s[i] > '9')) {
			return vector<int> ();
		} else if (s[i] == ' ') {
			if (curint != 0) {
				curint = positive ? curint : -curint;
				integers.push_back(curint);
				curint = 0;
				positive = true;
			}
		} else if (s[i] == '-') {
			positive = false;
		}else {
			curint = curint * 10 + s[i] - '0';
		}
	}
	return integers;
}