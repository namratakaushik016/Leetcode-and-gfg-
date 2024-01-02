class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        //initalizing two varibales left is set to 1 and right is set to a large value
        long left=1, right=1e10;
        
        
        //calculating the lcm of divisor1 and divisor2 and store it in the variable divisor
        long divisor= lcm((long)divisor1, (long)divisor2);
        
        while(left<right){
            long mid=left+(right-left)/2;
            
            //Count of numbers not divisible by divisor1 up to mid
            long cnt1= mid / divisor1 * (divisor1 - 1) + mid % divisor1;
            //Count of numbers not divisible by divisor2 up to mid
            long cnt2= mid / divisor2 * (divisor2 - 1) + mid % divisor2;
            //Count of numbers not divisible by divisor up to mid
            long cnt= mid / divisor * (divisor - 1) + mid % divisor;
            
            if(cnt1>=uniqueCnt1 && cnt2>=uniqueCnt2 && cnt>=uniqueCnt1+uniqueCnt2 ){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
        
    }
};