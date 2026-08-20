class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=nums[0], ans=nums[0];
        int best=nums[0], worst=nums[0];
        int bestsum=nums[0];
        for (int i=1; i<nums.size(); i++){
            int a=nums[i]+best;
            int b=nums[i];
            int c=nums[i]+worst;
            best=max(a, max(b, c));
            worst=min(a, min(b, c));
            ans=max(ans, best);
            bestsum=min(bestsum, worst);
            sum+=nums[i];
        }
        if (ans<0){
            return ans;
        }
        return max(ans, sum-bestsum);
    }
};