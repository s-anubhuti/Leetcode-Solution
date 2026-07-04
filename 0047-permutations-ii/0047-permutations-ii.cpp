class Solution {
public:
    void getPermutation(vector<int> & nums, int i, vector<vector<int>> &permutation) {
        if (i == nums.size()) {
            permutation.push_back({nums});
            return;
        }

        unordered_set<int> seen;
        for (int j = i; j < nums.size(); j++) {
            if (seen.count(nums[j])) {
                continue;
            }
            seen.insert(nums[j]);
            
            swap(nums[i], nums[j]);
            getPermutation(nums, i + 1, permutation);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutation;
        sort(nums.begin(), nums.end());
        getPermutation(nums, 0, permutation);

        return permutation;
    }
};