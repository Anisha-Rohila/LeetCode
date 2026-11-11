class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>number;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                number.push_back(nums[i]);
            }
        }
        int k=number.size();
        for(int i=0;i<k;i++){
            nums[i]=number[i];
        }
        return k;
    }
};