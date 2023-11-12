class Solution {
public:
// According to Principle of Inclusion and Exclusion, we can just simply minus the repeat part.
// a. three kids with any number of candies= n+2C2
 
// b. one kid with more than limit number of candies= n+2-(limit+1)C2 ​
 
// c. two kids with more than limit number of candies= n+2-2*(limit+1)C2
 
// d. three kids with more than limit number of candies= n+2-3*(limit+1)C2
 
// From the principle above, we get ANS = 1∗a−3∗b+3∗c−d1*a -3*b +3*c -d1∗a−3∗b+3∗c−d
    long long distributeCandies(long long n, long long limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = (n+1)*(n+2)/2;
        if (n > limit) {
            ans -= 3*(n-limit+1)*(n-limit)/2;
        }
        if (n - 2 >= 2 * limit) {
            ans += 3*(n-2*limit)*(n-2*limit-1)/2;
        }
        return ans;
    }
};