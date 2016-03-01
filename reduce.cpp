//If more than one same variables appear in one line, just leave one in that line.
//If contrary variables appear in one line, this line is definitely satisfied, so just remove this line.
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "additional_functions.h"

void reduce(vector<vector<int> > &cnf) {
	for (int i = 0; i < cnf.size(); ++i) {
		unordered_set<int> cache;
		for (int j = 0; j < cnf[i].size(); ++j) {
			if (cache.find(cnf[i][j]) != cache.end()) {
				cnf[i].erase(cnf[i].begin()+j);
				--j;
			} else if (cache.find(-cnf[i][j]) != cache.end()) {
				cnf.erase(cnf.begin()+i);
				--i;
				break;
			} else {
				cache.insert(cnf[i][j]);
			}
		}
	}
}