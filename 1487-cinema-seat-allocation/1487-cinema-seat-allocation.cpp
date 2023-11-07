class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n*2;
        map<int,unordered_set<int>>m;
        for(auto i:reservedSeats)
        {
            m[i[0]].insert(i[1]);
        }
        for(auto i:m)
        {
            unordered_set<int>seats = i.second;
            if(seats.count(1))
            seats.erase(1);
            if(seats.count(10))
            seats.erase(10);
            if(seats.size()==0)
            continue;
            if((seats.find(2) == seats.end() && seats.find(3) == seats.end() && seats.find(4) == seats.end() && seats.find(5) == seats.end())
            ||
            (seats.find(6) == seats.end() && seats.find(7) == seats.end() && seats.find(4) == seats.end() && seats.find(5) == seats.end())
            ||
            (seats.find(6) == seats.end() && seats.find(8) == seats.end() && seats.find(9) == seats.end() && seats.find(7) == seats.end()))     
            ans-=1;
            else
            ans-=2;
        }
        return ans;
    }
};