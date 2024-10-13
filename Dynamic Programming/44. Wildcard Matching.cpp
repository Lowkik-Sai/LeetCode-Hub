
    /*
    Time complexity : O(n * m)
    Space complexity : O(n * m)
    */


class Solution {
public:
    bool isAllStars(string &S1, int i) {
        for (int j = i; j < S1.size(); j++) {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    bool checkMatch(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(i >= s.size() && j >= p.size()) return true;
        if(j >= p.size()) return false;
        if(i >= s.size()) return isAllStars(p, j);
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = false;
        if(p[j] == s[i] || p[j] == '?'){
            dp[i][j] = checkMatch(s, p, i+1, j+1, dp);
        } else if(p[j] == '*'){
            dp[i][j] = checkMatch(s, p, i+1, j, dp) | checkMatch(s, p, i, j+1, dp);
        }
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return checkMatch(s, p, 0, 0, dp);
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/wildcard-matching/
    */

    