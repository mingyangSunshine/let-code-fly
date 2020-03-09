| topic | difficulty | link |
| ---   | ---        | ---  |
| math | easy | [detail](https://leetcode.com/problems/set-mismatch/) |

# use c++ hash table.
```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> temp;
		vector<int> res;
		int total = nums.size() * (nums.size()+1) / 2;
		int sum = 0;

		for (auto num : nums) {
			if (temp.find(num) == temp.end()) {
				temp.insert(num);
			} else {
				res.push_back(num);
			}
			sum += num;
		}
		res.push_back(res[0]+total-sum);
		return res;
    }
};
```

# other solution - O(n) complexity, invert nums[abs(nums[i])-1] value to negative.
```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		vector<int> res;
		int sum = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			sum += abs(nums[i]);
			if (nums[abs(nums[i])-1] > 0) {
				nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
			} else {
				res.push_back(abs(nums[i]));
			}
		}
		res.push_back(res[0] + nums.size() * (nums.size()+1) / 2 - sum);

		return res;
    }
};
```

# note
- 
