//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
   const int mod=1e9+7;
    long long countWays(int n,vector<int>&dp){
        if(n==0 or n==1)return 1;
        if(n==2)return 2;
        if(dp[n]!=-1)return dp[n];
        int ways1=countWays(n-1,dp);
        int ways2=countWays(n-2,dp);
        int ways3=countWays(n-3,dp);
        return dp[n]=((ways1%mod+ways2%mod)%mod+ways3%mod)%mod;
    }
long long countWays(int n){
vector<int>dp(n+1,-1);
long long ans=countWays(n,dp);
return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends