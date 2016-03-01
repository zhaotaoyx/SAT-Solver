#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include "additional_functions.h"

using namespace std;

void PrintRemaining(vector<vector<int> > &cnf) {
	for (int i = 0; i < cnf.size(); ++i) {
		for (int j = 0; j < cnf[i].size(); ++j) {
			cout << cnf[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void PrintResult(unordered_map<int, bool> &result) {
	cout << "ASSIGNMENT: " << endl;
	for (pair<int, bool> key : result) {
		if (key.second) {
			cout << key.first << " = 1, ";
		} else {
			cout << key.first << " = 0, ";
		}
	}
	cout << endl;
}