//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int minimumMultiplications(vector<int>& arr, int start, int end) {
                int mod=1e5;
        queue<int>q;
        int level=0;
        q.push(start%mod);
        int mp[100001]={0};
        
        while(!q.empty()){
            
            int size=q.size();
            
            for(int i=0;i<size;i++){
                int x=q.front();
                q.pop();
                if(x==end)return level;
                
                for(auto &it:arr){
                   int y=(x*it)%mod;
                   if(mp[y]==0){
                       q.push((x*it)%mod);
                       mp[y]=1;
                   }
                }
                
                
            }
            level++;
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends