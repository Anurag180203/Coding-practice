class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(fx==sx && fy==sy)
            return t!=1;
        if(fx==sx || fy==sy)
            return t>=max(abs(fx-sx),abs(fy-sy));
        if(fx>sx) {
            int dista = fx-sx,distb = abs(fy-sy);
            int ans = min(dista,distb);
            ans += max(dista-ans,distb-ans);
            return ans<=t;
        }
        int dista = sx-fx,distb = abs(fy-sy);
        int ans = min(dista,distb);
        ans += max(dista-ans,distb-ans);
        return ans<=t;
    }
};