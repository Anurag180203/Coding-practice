class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>indeg(n,0),vis(n,0);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(!indeg[i])
            {
                if(idx!=-1)
                    return -1;
                idx=i;
            }
        }
        // vis[idx]=1;
        // queue<int>q;
        // q.push(idx);
        // while(!q.empty())
        // {
        //     int sz = q.size();
        //     while(sz--)
        //     {
        //         int f = q.front();
        //         q.pop();
        //         for(auto i:adj[f])
        //         {
        //             if(!vis[i])
        //             {
        //                 q.push(i);
        //                 vis[i]=1;
        //             }
        //         }
        //     }
        // }
        // if(accumulate(vis.begin(),vis.end(),0)==n) return idx;
        // return -1;
        return idx;
    }
};