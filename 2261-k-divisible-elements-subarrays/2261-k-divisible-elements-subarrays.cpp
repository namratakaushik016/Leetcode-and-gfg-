class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
       set<vector<int>>s;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                vector<int> arr;
                int count = 0;
                for(int l = i; l <= j; l++){
                    arr.push_back(nums[l]);
                    if(nums[l]%p == 0){
                        count++;
                    }
                }
                if(count <= k){
                    s.insert(arr);
                }
            }
        }
        return s.size();
    }
};