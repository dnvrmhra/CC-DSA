class Solution {
public:
    int sumOfSquares(int n) {
        int sum=0;
        while (n){
            int dig=n%10;
            sum+=dig*dig;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n){
        int slow=n;
        int fast=sumOfSquares(n);
        while (fast!=1 && slow!=fast){
            slow=sumOfSquares(slow);
            fast=sumOfSquares(sumOfSquares(fast));
        }
        return fast==1;
    }
};