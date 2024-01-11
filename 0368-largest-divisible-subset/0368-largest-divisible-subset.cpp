class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;

        if (nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(nums.size(), vector<int>());

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> maxSubset;
            
            for (int k = 0; k < i; ++k) {
                if (nums[i] % nums[k] == 0 && maxSubset.size() < dp[k].size()) {
                    maxSubset = dp[k];
                }
            }

            dp[i] = maxSubset;
            dp[i].push_back(nums[i]);
        }

        for (int i = 0; i < dp.size(); ++i) {
            if (result.size() < dp[i].size()) {
                result = dp[i];
            }
        }

        return result;
    }
};