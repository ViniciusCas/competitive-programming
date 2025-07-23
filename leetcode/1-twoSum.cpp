#include "../fastcp.h"

class Solution {
public:
    // time complexity: O(n^2)
    // space complexity: O(1)
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        for (int i=0; i < nums.size(); i++) {
            for (int j=i+1; j < nums.size(); j++) {
                if (nums[i]+nums[j] == target) return {i,j};
            }
        }

        return {};
    }

    // time complexity: O(n)
    //   The time complexity is O(n) because the hashmap search is O(1)
    // space complexity: O(n)
    vector<int> twoSumOptimal(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;

        for (int i=0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i=0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end() && map[complement] != i) {
                return {i, map[complement]};
            }
        }

        return {};
    }

};