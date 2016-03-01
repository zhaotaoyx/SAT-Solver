#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> StringToIntegers(string s);
void PrintRemaining(vector<vector<int> > &cnf);
void PrintResult(unordered_map<int, bool> &result);
void reduce(vector<vector<int> > &cnf);
bool assign(vector<vector<int> > &cnf, int target, unordered_map<int, int> &remaining, unordered_map<int, bool> &result);
int heuristic(unordered_map<int, int> &remaining);