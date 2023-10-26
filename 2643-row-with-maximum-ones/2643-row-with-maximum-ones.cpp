class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        //onecount->will store max number of 1's in a row
        int onecount = INT_MIN;
        //rowno->will store index of max no.of 1'swali row
        int rowno=0;
        for(int i=0;i<n;i++){
          int count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            if(count>onecount){
                onecount=count;
                rowno=i;
            }
        }
        ans.push_back(rowno);
        ans.push_back(onecount);
        return ans;
    }
};