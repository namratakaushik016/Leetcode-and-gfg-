//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool checkcycle(int i, vector<int> adj[], int *vis){
      vis[i]=1;
      for(auto it : adj[i]){
          if(!vis[it]){
              if(checkcycle(it, adj, vis)) return true;
          }
          else if(vis[it]==1) return true;
      }
      vis[i]=2;
      return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       int vis[V]={0};
       vector<int>ans;
       for(int i=0; i<V; i++){
           if(!vis[i])
                checkcycle(i, adj, vis);
       }
       for(int i=0; i<V; i++){
           if(vis[i]==2)
                ans.push_back(i);
       }
       return ans;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends