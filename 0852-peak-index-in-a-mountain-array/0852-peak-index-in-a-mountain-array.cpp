class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() -1;

        int mid = s + (e-s)/2;

        while(s<e)
        {
            if(arr[mid]<arr[mid+1])
            {
                //a wali line mai hu
                //mtlb a[i]<a[i+1]
                //peak element right mai exist krtaa hai
                s = mid+1;
            }
            else{
                //ya to mai b line pr hu
                //ya to mai peak pr hu
                
                e = mid;
            }
            //mid ko update kkrdiaa
             mid = s + (e-s)/2;
        }
        return s;
    }
};