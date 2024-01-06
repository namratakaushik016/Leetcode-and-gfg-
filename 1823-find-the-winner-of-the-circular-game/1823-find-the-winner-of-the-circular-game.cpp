class Solution {
private:
    int helper(int n,int k){
        if(n==1){//in case of only 1 player
            return 0;
        }
        return ((k+1)%n + helper(n-1,k))%n;
    }
public:
    int findTheWinner(int n, int k) {
        return helper(n,k-1)+1;
    }
};