class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = growTime.size();
        vector<pair<double,int>>v(n);
        for(int i=0;i<n;i++)
            v[i] = {(double)1/growTime[i],i};
        sort(v.begin(),v.end());
        for(auto i:v)
        {
            cout<<i.second<<" ";
        }
        int ans=0,x=0;
        for(auto i:v)
        {
            ans += plantTime[i.second];
            x -= plantTime[i.second];
            x = max(0,x);
            x = max(x,growTime[i.second]);
        }
        return ans+x;
    }
};