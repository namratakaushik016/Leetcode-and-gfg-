class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
    bool check_alright=true;
    int mini_val=-1;
    int count=0;
    
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i;j<nums.size();j++)
        {
            for(int k=0;k<nums.size();k++)
            {
                if(k>=i && k<=j)
                continue;
                if(mini_val>=nums[k])
                {
                    check_alright=false;
                    break;
                }
                mini_val=nums[k];
            }
            if(check_alright)
            {
                count++;
            }
            check_alright=true;
            mini_val=-1;
        }
    }
        return count;
    }
};