class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=0,ans=0;
        mid=n%2==0?(nums[n/2]+nums[n/2-1])/2:nums[n/2];
        for(auto it:nums){
            ans+=abs(it-mid);
        }
        return ans;
    
    }
};