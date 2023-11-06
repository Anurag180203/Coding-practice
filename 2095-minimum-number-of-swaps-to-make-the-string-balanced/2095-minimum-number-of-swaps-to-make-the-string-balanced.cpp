class Solution {
public:
    int minSwaps(string s) {
        int ans=0,o=0;
        for(auto i:s)
        {
            if(i==']')
            {
                if(o)
                o--;
                else
                ans++;
            }
            else
            {
                o++;
            }
        }
        return (ans+o)/4+((ans+o)%4?1:0);
    }
};