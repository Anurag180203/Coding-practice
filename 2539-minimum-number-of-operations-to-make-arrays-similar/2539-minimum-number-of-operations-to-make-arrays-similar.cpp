class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        vector<int>a,b,c,d;
        for(auto i:nums)
        {
            if(i&1)
                a.push_back(i);
            else
                b.push_back(i);
        }
        for(auto i:target)
        {
            if(i&1)
                c.push_back(i);
            else
                d.push_back(i);
        }
        long long ans=0;
        for(int i=0;i<a.size();i++)
            ans+=(abs(a[i]-c[i]));
        for(int i=0;i<b.size();i++)
            ans+=(abs(b[i]-d[i]));
        return ans/4;
    }
};