class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>ans;
        for(int i=0;i<nums.size();i++){
            int sum=target-nums[i];
            if(ans.find(sum)!=ans.end()){
                return {ans[sum],i};
            }
            ans[nums[i]]=i;
        }
    return{};
    }
};