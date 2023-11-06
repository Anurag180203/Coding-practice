class Solution {
public:
    void f(int idx,int open,string &s,string temp,set<string>&v) {
        if(open>s.size()-idx)
            return;
        if(idx==s.size()) {
            if(!open)
            {
                if(v.empty())
                {
                    v.insert(temp);
                    return;
                }
                int sz = (*v.begin()).size();
                if(sz == temp.size())
                    v.insert(temp);
                else if(temp.size() > sz) {
                    v = set<string>();
                    v.insert(temp);
                }
            }
            return;
        }
        if(s[idx]==')') {
            if(open)
                f(idx+1,open-1,s,temp+')',v);
            f(idx+1,open,s,temp,v);
        }
        else if(s[idx]=='(') {
            f(idx+1,open,s,temp,v);
            f(idx+1,open+1,s,temp+'(',v);
        }
        else {
            f(idx+1,open,s,temp+s[idx],v);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        set<string>v;
        f(0,0,s,"",v);
        int len=0;
        for(auto i:v)
            ans.push_back(i);
        return ans;
    }
};