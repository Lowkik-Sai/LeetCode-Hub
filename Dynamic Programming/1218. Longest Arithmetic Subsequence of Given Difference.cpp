
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */

class Solution {
public:
    int getLongestSeq(vector<int>& arr, int& diff, int i, int prev, vector<vector<int>>& dp){
        if(i >= arr.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int pick = 0;
        int noPick = getLongestSeq(arr, diff, i+1 , prev, dp);
        if( prev == -1 || ((arr[i] - arr[prev]) == diff)){
            pick = 1 + getLongestSeq(arr, diff, i+1 ,i, dp);
        }
        return dp[i][prev+1] = max(pick, noPick);
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        vector<int> dp(n, 1);
        map<int, int> mapping;
        int maxLen = INT_MIN;
        for(int i = 0; i < n; i++){
            if((mapping.find(arr[i] - difference) != mapping.end())){
                dp[i] = dp[mapping[arr[i] - difference]] + 1;
            }
            mapping[arr[i]] = i;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
    */

    
