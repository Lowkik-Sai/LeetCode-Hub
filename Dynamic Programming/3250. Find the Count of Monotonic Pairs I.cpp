
    /*
    Time complexity : O(n * (maxSum + 1)^2) - N is size of the given arr
    Space complexity : O(n * maxSum ) - For Visited arr of size N
    */

class Solution {
public:
    int mod = 1e9 + 7;
    int count(vector<int>& nums, int i, int prev, vector<vector<int>>& dp){
        if(i >= nums.size()) return 1;
        if(dp[i][prev] != -1) return dp[i][prev];
        int c = 0;
        for(int val = prev ; val <= nums[i]; val++){
            int prev1 = nums[i] - val;
            if(i == 0 || nums[i-1] - prev >= prev1){
                c = ( c + count(nums, i+1, val, dp)) % mod;
            }
        }
        
        return dp[i][prev] = c;
    }
    
    int countOfPairs(vector<int>& nums) {
        int maxSum = 0;
        for(auto& i : nums) maxSum = max(maxSum, i);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(maxSum + 1, -1));
        return count(nums, 0, 0, dp);
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/description/
    */
