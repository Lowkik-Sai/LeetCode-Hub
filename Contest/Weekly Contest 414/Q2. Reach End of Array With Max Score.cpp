
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */


class Solution {
public:
    long long findScore(vector<int>& nums, int i, vector<long long>& dp) {
        int n = nums.size();
        if (i == n - 1) return 0;
        if (dp[i] != -1) return dp[i]; 
        
        long long maxScore = 0;
        
        for (int j = i + 1; j < n; ++j) {
            long long jumpScore = (j - i) * nums[i]; 
            maxScore = max(maxScore, jumpScore + findScore(nums, j, dp));
        }
        
        return dp[i] = maxScore; 
    }

    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        // vector<long long> dp(n, -1); 
        // return findScore(nums, 0, dp);
        long long score = 0;
        long long lastScore = nums[0];
        int currInd = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > lastScore){
                score += (i-currInd) * lastScore;
                lastScore = nums[i];
                currInd = i;
            }
        }
        return score + (n-currInd-1) * lastScore;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/reach-end-of-array-with-max-score/description/
    */

    
