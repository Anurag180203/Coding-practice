//Assuming there is a point, on the left of the point, all elements add K, on the right of the point, all elements substract K, check each possible point. (a point is between two numbers).
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=nums[nums.size()-1]-nums[0];
        int left=nums[0]+k;
        int right=nums[nums.size()-1]-k;
        for(int i=0;i<nums.size()-1;i++){
            int s=min(left,nums[i+1]-k);
            int t=max(right,nums[i]+k);
            res=min(res,t-s);
        }
        return res;
    }
};