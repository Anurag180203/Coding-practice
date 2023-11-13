class Solution {
public:
    string sortVowels(string s) {
        string x = "";
        for(auto i:s)
        {
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U')
            x+=i;
        }
        sort(x.begin(),x.end());
        int idx=0;
        for(auto &i:s)
        {
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U')
            {
                i=x[idx++];
                if(idx==x.size())
                break;
            }
        }
        return s;
    }
};