class Solution {
public:
    int findpivotindex(vector<int>& nums){
        int n=nums.size();
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        
        while(s<=e){
            //corner case
            if(s==e)//agr single element hai to wahi return kra do
                return s;
            if(mid+1<n && nums[mid]>nums[mid+1])
                return mid;
            else if(mid-1>=0 && nums[mid]<nums[mid-1])
                return mid-1;
            else if(nums[s]>nums[mid]){
                e=mid-1;
                
            }
                
            else
                s=mid+1;
            mid=s+(e-s)/2;
            
        }
        return -1;
        
    }
    int binarysearch(vector<int>&arr,int s,int e,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                return mid;
                
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
            
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivotindex=findpivotindex(nums);
        int n=nums.size();
        int ans=-1;
        
        //search in A
        if(target >= nums[0] && target<=nums[pivotindex]){
            ans=binarysearch(nums,0,pivotindex,target);
        }
        else{
            ans=binarysearch(nums,pivotindex+1,n-1,target);
        }
            
        return ans;
        
    }
};