
    /*
    Time complexity : O(n1 * n2)
    Space complexity : O(n1 * n2)
    */


class Solution {
public:
    int getLength(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        if(i >= text1.size() || j >= text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxLen = 0;
        if(text1[i] == text2[j]){
            maxLen = 1 + getLength(text1, text2, i+1, j+1, dp);
        }else{
            maxLen = max({maxLen, getLength(text1, text2, i+1, j, dp), getLength(text1, text2, i, j+1, dp)});
        }

        return dp[i][j] = maxLen;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return getLength(text1, text2, 0, 0, dp);
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/longest-common-subsequence/submissions/
    */

    