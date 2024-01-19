class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
        return 1.00;
        
     //If there are more than 1 passenger then the chance of a passenger getting his seat is 50%.
        return 0.50;
    }
};