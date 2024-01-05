class Solution {
public:
    
    const vector<int>direction{-1,0,1,0,-1};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();//number of rows
        int n=isWater[0].size();//number of columns.
        
        vector<vector<int>>ans(m,vector<int>(n));
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=isWater[i][j]-1;//water cell become 0 and land cells become -1.
                if(ans[i][j]==0){
                    q.emplace(i,j);
                }
            }
        }
        while(!q.empty()){
            auto[i,j]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                 int x = i + direction[k];    // Calculating the new x-coordinate.
                int y = j + direction[k + 1];// Calculating the new y-coordinate.
                
                 if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                     ans[x][y] = ans[i][j] + 1;
                     q.emplace(x,y);
                
            }
        }
    }
        return ans;
    }
};