| topic | difficulty | link |
| ---   | ---        | ---  |
| backtracking | medium | [detail](https://leetcode-cn.com/problems/combinations/) |

```c++
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
```

# note
1、本题所用思想为回溯和剪枝，回溯通过`push_back()`与`pop_back`实现，
    剪枝由`else if (n - start + 1 < k)`实现，条件不满足时，无需执行该分支。
2、对二维vector的操作不够熟悉。