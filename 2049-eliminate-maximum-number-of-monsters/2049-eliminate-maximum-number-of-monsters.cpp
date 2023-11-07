class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<pair<double,int>>v(n);
        for(int i=0;i<n;i++)
            v[i] = {(double)(dist[i])/speed[i],i};
        sort(v.begin(),v.end());
        int ans=1;
        for(int i=1;i<n;i++) {
            int idx = v[i].second;
            if(dist[idx]>speed[idx]*ans)
                ans++;
            else
                break;
        }
        return ans;
    }
};