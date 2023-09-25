//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here 
         set<pair<int,int>>s;
        priority_queue<pair<int,pair<int,int>>>pq;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        pq.push({A[N-1]+B[N-1],{N-1,N-1}});
         s.insert({N-1,N-1});
         vector<int>ans;
        while(!pq.empty()&&K--){
            int t=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            ans.push_back(t);
            pq.pop();
             if(y-1>=0&&s.find({x,y-1})==s.end()){
                 pq.push({A[x]+B[y-1],{x,y-1}});
                 s.insert({x,y-1});
             }
             if(x-1>=0&&s.find({x-1,y})==s.end()){
                 pq.push({A[x-1]+B[y],{x-1,y}});
                  s.insert({x-1,y});
             }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends