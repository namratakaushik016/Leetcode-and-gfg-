//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
   vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        vector<int>ans(2,-1);
        int a=0,b=m-1,min=INT_MAX;
        while(a<n&&b>=0){
            int cur=arr[a]+brr[b];
            if(abs(cur-x)<min){
                ans={arr[a],brr[b]};
                min=abs(cur-x);
            }
            if(cur>=x){
                b--;
            }
            else a++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends