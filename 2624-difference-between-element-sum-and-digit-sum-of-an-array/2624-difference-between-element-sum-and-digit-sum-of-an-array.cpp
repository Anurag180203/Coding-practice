class Solution {
private:
    int digitSum(int num){
        int ans=0;
        while(num)
        {
            ans+=num%10;
            num/=10;
        }
        return ans;
    }
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1=0,sum2=0;
        for(auto i:nums)
        {
            sum1+=i;
            sum2+=digitSum(i);
        }
        return sum1-sum2;
    }
};