class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Starting sliding window
        int startIndex = 0;
        int endIndex = k;
        while (endIndex < nums.size()) {
            sum -= nums[startIndex];
            startIndex++;
            
            sum += nums[endIndex];
            endIndex++;

            maxSum = max(maxSum, sum);
        }

        return (double) maxSum / k;
    }
};
