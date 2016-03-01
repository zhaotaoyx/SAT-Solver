#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include "additional_functions.h"

using namespace std;


bool assign(vector<vector<int> > &cnf, int target, unordered_map<int, int> &remaining, unordered_map<int, bool> &result) {
	if (target != 0) {
		result[target] = true;
	}
	remaining.erase(-target);
	int next_assign = 0;
	for (int i = 0; i < cnf.size(); ++i) {
		if (next_assign == 0 && cnf[i].size() == 1 && result.find(cnf[i].front()) == result.end() &&
			result.find(-cnf[i].front()) == result.end()) {
			next_assign = cnf[i].front();
		}
		for (int j = 0; j < cnf[i].size(); ++j) {
			if (cnf[i][j] == target) {
				for (int k = 0; k < cnf[i].size(); ++k) {
					if (--remaining[cnf[i][k]] == 0) {
						remaining.erase(cnf[i][k]);
					}
				}
				cnf.erase(cnf.begin()+i);
				--i;
				break;
			} else if (cnf[i][j] == -target) {
				cnf[i].erase(cnf[i].begin()+j);
				if (cnf[i].empty()) {
					return false;
				}
				--j;
			} else if (next_assign == 0) {
				if (remaining.find(-cnf[i][j]) == remaining.end() && result.find(cnf[i][j]) == result.end() &&
					result.find(-cnf[i][j]) == result.end()) {
					next_assign = cnf[i][j];
				}
			}
		}
	}
	if (next_assign != 0 && !assign(cnf, next_assign, remaining, result)) {
		return false;
	}
	return true;
}


int heuristic(unordered_map<int, int> &remaining) {
	int MaxTimes = 0;
	int AppearedMost = 0;
	for (pair<int, int> cur : remaining) {
		if (cur.second > MaxTimes) {
			AppearedMost = cur.first;
		}
	}
	return AppearedMost;
}