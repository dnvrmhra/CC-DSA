/**class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        unordered_map<int,int>seen;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if(seen.count(nums[i]) && i-seen[nums[i]]<=k){
                return true;
            }
            seen[nums[i]]=i;
        }
        return false;
    }
};
*/

class Solution{
    public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        unordered_set<int> window;
        for (int i=0;i<nums.size();i++){
            if (i>k){
                window.erase(nums[i-k-1]);
            }
            if(window.count(nums[i])){
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};