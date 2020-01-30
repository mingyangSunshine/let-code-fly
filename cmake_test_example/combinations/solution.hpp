#ifndef __SOLUTION_HPP__
#define __SOLUTION_HPP__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	vector<vector<int>> result;
	void combine_sub(vector<int>& arr, int start, int n, int k) {
		if (k == 0) {
			result.push_back(arr);
			return;
		}
		else if (n - start + 1 < k) {
			return;
		}

		/* include the first number */
		arr.push_back(start);
		combine_sub(arr, start + 1, n, k - 1);
		arr.pop_back();
		/* not include the first number */
		combine_sub(arr, start + 1, n, k);
	}

public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> array;
		result.clear();

		if (n < 0 || k < 0)
			return result;
		combine_sub(array, 1, n, k);
		return result;
	}
};

#endif