class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i=0,j=1,ans=-1,temp=0;
        while(i<arr.size() && j<arr.size())
        {
            if(temp==k)
            return ans;
            if(arr[i]>arr[j])
            {
                if(j>i)
                j++;
                else
                j=i+1;
                if(ans==arr[i])
                temp++;
                else
                temp=1;
                ans=arr[i];
            }
            else
            {
                if(j>i)
                i = j+1;
                else
                i++;
                if(ans==arr[j])
                temp++;
                else
                temp=1;
                ans=arr[j];
            }
        }
        if(i<arr.size())
            return arr[i];
        return arr[j];
    }
};