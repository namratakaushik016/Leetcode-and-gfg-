//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int MotherVertex=-1;
    void dfs(vector<int> adj[],vector<bool>& vis,int node){
        vis[node]=true;
        for(auto i:adj[node]){
            if(!vis[i]) dfs(adj,vis,i);
        }
        MotherVertex=node;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(adj,vis,i);
	    }
	    
	    vis=vector<bool>(V,0);
	    
	    dfs(adj,vis,MotherVertex);
	    bool isMotherVertex=true;
	    
	    for(int i=0;i<V;i++) if(!vis[i]) isMotherVertex=false;
	    return isMotherVertex?MotherVertex:-1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends