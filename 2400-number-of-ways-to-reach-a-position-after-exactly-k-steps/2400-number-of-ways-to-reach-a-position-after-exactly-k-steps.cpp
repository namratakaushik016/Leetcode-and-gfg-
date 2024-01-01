class Solution {
public:
    long long dp[4001][1001];
    long long count(int currentvertex,int target,int k){
        if(k==0 && currentvertex==target)
            return 1;
        if(k==0)
            return 0;
        if(dp[currentvertex+1000][k]!=-1)
            return dp[currentvertex+1000][k];
        long long a=count(currentvertex+1,target,k-1);
        a+=count(currentvertex-1,target,k-1);
        return dp[currentvertex+1000][k]=a%1000000007;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        for(int i=0;i<=3001;i++)
            for(int j=0;j<=k;j++)
                dp[i][j]=-1;
            long long ans=count(startPos,endPos,k);
            return ans%1000000007;
        }
        
        
    
};