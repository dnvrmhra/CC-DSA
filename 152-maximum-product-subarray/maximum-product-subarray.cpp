class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestProd=nums[0], ans=nums[0], worstProd=nums[0];
        for (int i=1;i<nums.size(); i++){
            int a=nums[i]*bestProd;
            int b=nums[i];
            int c=nums[i]*worstProd;
            bestProd=max(a, max(b,c));
            worstProd=min(a,min(b,c));
            ans=max(bestProd,ans);
        }
        return ans;
    }
};