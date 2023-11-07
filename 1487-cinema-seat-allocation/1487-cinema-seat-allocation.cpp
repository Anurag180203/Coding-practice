// class Solution {
// public:
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         int ans = n*2;
//         unordered_map<int,unordered_set<int>>m;
//         for(auto i:reservedSeats)
//         {
//             m[i[0]].insert(i[1]);
//         }
//         for(auto i:m)
//         {
//             unordered_set<int>seats = i.second;
//             if(seats.count(1))
//             seats.erase(1);
//             if(seats.count(10))
//             seats.erase(10);
//             if(seats.size()==0)
//             continue;
//             if((seats.find(2) == seats.end() && seats.find(3) == seats.end() && seats.find(4) == seats.end() && seats.find(5) == seats.end())
//             ||
//             (seats.find(6) == seats.end() && seats.find(7) == seats.end() && seats.find(4) == seats.end() && seats.find(5) == seats.end())
//             ||
//             (seats.find(6) == seats.end() && seats.find(8) == seats.end() && seats.find(9) == seats.end() && seats.find(7) == seats.end()))     
//             ans-=1;
//             else
//             ans-=2;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> cache;

        for (auto& seat : reservedSeats) {
            cache[seat[0]].push_back(seat[1]);
        }

        int families = 0;

        // Automatically account for rows with no reservations
        families += (n - cache.size()) * 2;

        for (auto& row : cache) {
            vector<int>& seats = row.second;
            bool left = true, middle = true, right = true;

            for (int& seat : seats) {
                if (seat >= 2 && seat <= 5) left = false;
                if (seat >= 4 && seat <= 7) middle = false;
                if (seat >= 6 && seat <= 9) right = false;
            }

            if (left && right) families += 2;
            else if (left || middle || right) families += 1;
        }

        return families;
    }
};