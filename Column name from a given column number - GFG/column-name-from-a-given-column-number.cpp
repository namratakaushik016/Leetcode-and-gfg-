//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
         // your code here
        string res="";
        while(n>0)
        {
            n--;
            int x=n%26;
            res+=((char)'A'+n%26);
            n=n/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends