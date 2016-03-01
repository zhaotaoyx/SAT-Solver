//
//  main.cpp
//  SAT_Problem_Solver
//
//  Created by Tao Zhao on 3/27/15.
//  Copyright (c) 2015 Tao Zhao. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "additional_functions.h"
#include "string_to_integers.cpp"
#include "print.cpp"
#include "reduce.cpp"
#include "assign.cpp"

using namespace std;


bool ApplyDPLL(vector<vector<int> > &cnf, unordered_map<int, int> &remaining, unordered_map<int, bool> &result) {
	
	int next_assign = heuristic(remaining);
	
	vector<vector<int> > temp_cnf = cnf;
	unordered_map<int, int> temp_remaining = remaining;
	unordered_map<int, bool> temp_result = result;

	if (assign(cnf, next_assign, remaining, result)) {
		if (cnf.empty()) {
			return true;
		} else if (ApplyDPLL(cnf, remaining, result)) {
			return true;
		}
	}
	
	cnf = temp_cnf;
	remaining = temp_remaining;
	result = temp_result;

	if (assign(cnf, -next_assign, remaining, result)) {
		if (cnf.empty()) {
			return true;
		} else if (ApplyDPLL(cnf, remaining, result)) {
			return true;
		}
	}
	return false;
}

int main() {

	vector<vector<int> > cnf; // this is the data of the input cnf file
	unordered_map<int, int> remaining;
	unordered_map<int, bool> result;

	//cout << "Please enter your input file name: " << endl;

	string filename;
	cin >> filename;
	ifstream file (filename);

	if (file.is_open()) {
		string line_s;
		while (getline(file, line_s)) {
			vector<int> line = StringToIntegers(line_s);
			if (!line.empty()) {
				cnf.push_back(line);
				for (int i = 0; i < line.size(); ++i) {
					++remaining[line[i]];
				}
			}
		}
		file.close();
	}
	/*
	cout << endl;
	cout << "Original function:" << endl;
	PrintRemaining(cnf);
	*/
	reduce(cnf);

	if (!assign(cnf, 0, remaining, result)) {
		cout << "RESULT: UNSAT" << endl;
		return 0;
	}
	if (cnf.empty()) {
		cout << "RESULT: SAT" << endl;
		PrintResult(result);
		return 0;
	}


	if (ApplyDPLL(cnf, remaining, result)) {
		cout << "RESULT: SAT" << endl;
		PrintResult(result);
	} else {
		cout << "RESULT: UNSAT" << endl;
	}

	return 0;
}



