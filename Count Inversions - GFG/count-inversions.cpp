//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   
         long long count=0;
   void mer(long long arr[],int l,int mid,int r)
    {
        int i=l,j=mid+1;
        vector<long long int>ans;
        while(i<=mid && j<=r)
        {
            if(arr[i]>arr[j])
            {
                 count+=(mid-i)+1;
                ans.push_back(arr[j++]);
               
            }
            else
            {
                ans.push_back(arr[i++]);
            }
        }
        while(i<=mid)
        {
              ans.push_back(arr[i++]);
        }
        while(j<=r)
        {
            ans.push_back(arr[j++]);
        }
        for(int i=l;i<=r;i++)
        {
            arr[i]=ans[i-l];
        }
       
    }
    void mersort(long long arr[],int l,int r)
    {
        if(l<r)
        {
        long long int mid=(l+r)/2;
            mersort(arr,l,mid);
            mersort(arr,mid+1,r);
            mer(arr,l,mid,r);
        }
    }
    long long int inversionCount(long long arr[], long long n)
    {
       mersort(arr,0,n-1);
       return count;
    
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends