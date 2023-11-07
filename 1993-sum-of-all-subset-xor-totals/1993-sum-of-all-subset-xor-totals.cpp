class Solution {
public:
    int ans=0;
    void f(int idx,vector<int>&nums,int sum)
    {
        if(idx<0)
        {
            ans+=sum;
            return;
        }
        f(idx-1,nums,sum);
        f(idx-1,nums,sum^nums[idx]);
    }
    int subsetXORSum(vector<int>& nums) {
        f(nums.size()-1,nums,0);
        return ans;
    }
};