class Solution {
public:
    int minNonZeroProduct(int p) {
        long long ans=1;
        int mod = 1000000007;
        long long even = 0;
        for (int i=1;i<p;i++) even = (even | (1LL<<i));
        long long t = ((1LL<<p)-1)/2;
        long long cnt=1;
        vector<long long> m;
        vector<long long> c;
        long long tEven=even;
        while (cnt<=t){
          m.push_back(tEven);
          c.push_back(cnt);
          tEven = ((tEven%mod)*(tEven%mod))%mod;
          cnt*=2;
        }

        while (t>0){
          int i = lower_bound(c.begin(),c.end(),t)-c.begin();
          if (i==c.size() || c[i]>t) i--;
          t-=c[i];
          ans = ((ans%mod)*(m[i]%mod))%mod;
        }
     
        even = (even|1)%mod;
        ans = ((ans%mod)*(even%mod))%mod;
        return ans;
    }
};