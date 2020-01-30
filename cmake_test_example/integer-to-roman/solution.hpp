#ifndef __SOLUTION_HPP__
#define __SOLUTION_HPP__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> Roman_table = {"M", "CM", "D", "CD", "C", "XC", "L", "XL",
                                  "X", "IX", "V", "IV", "I" };
	vector<int> Num_table = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	string intToRoman(int num) {
		string output;
		int radix_ind = 0;
		while (num > 0) {
			int res = num / Num_table[radix_ind];
			num = num % Num_table[radix_ind];
			while (res--) {
				output += Roman_table[radix_ind];
			}
			radix_ind++;
		}
		return output;
	}
};

#endif
