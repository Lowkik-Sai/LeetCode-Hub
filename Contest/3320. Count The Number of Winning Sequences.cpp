
    /*
    Time complexity : O(n^2)
    Space complexity : O(n^2)
    */


class Solution {
public:
    int mod = 1e9 + 7;

    int getCount(string& alice, int aliceScore, int bobScore, int ind, char prev, vector<vector<vector<int>>>& dp) {
        if (ind >= alice.size()) {
            if (aliceScore < bobScore) return 1;
            return 0;
        }

        // Using sum + n as offset to handle negative sum indexing like in code 2
        int sum = bobScore - aliceScore;
        int n = alice.size();
        if (sum + n < 0 || sum + n > 2 * n) return 0;

        if (dp[ind][sum + n][prev == '!' ? 0 : (prev == 'F' ? 1 : (prev == 'W' ? 2 : 3))] != -1) {
            return dp[ind][sum + n][prev == '!' ? 0 : (prev == 'F' ? 1 : (prev == 'W' ? 2 : 3))];
        }

        long long count = 0;

        if (alice[ind] == 'F') {
            if (prev != 'F') {
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'F', dp)) % mod;
            }
            if (prev != 'W') {
                bobScore += 1;
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'W', dp)) % mod;
                bobScore -= 1;
            }
            if (prev != 'E') {
                aliceScore += 1;
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'E', dp)) % mod;
                aliceScore -= 1;
            }
        } else if (alice[ind] == 'W') {
            if (prev != 'F') {
                aliceScore += 1;
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'F', dp)) % mod;
                aliceScore -= 1;
            }
            if (prev != 'W') {
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'W', dp)) % mod;
            }
            if (prev != 'E') {
                bobScore += 1;
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'E', dp)) % mod;
                bobScore -= 1;
            }
        } else if (alice[ind] == 'E') {
            if (prev != 'F') {
                bobScore += 1;
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'F', dp)) % mod;
                bobScore -= 1;
            }
            if (prev != 'W') {
                aliceScore += 1;
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'W', dp)) % mod;
                aliceScore -= 1;
            }
            if (prev != 'E') {
                count = (count + getCount(alice, aliceScore, bobScore, ind + 1, 'E', dp)) % mod;
            }
        }
        
        return dp[ind][sum + n][prev == '!' ? 0 : (prev == 'F' ? 1 : (prev == 'W' ? 2 : 3))] = count;
    }

    int countWinningSequences(string alice) {
        int aliceScore = 0, bobScore = 0;
        int n = alice.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 * n + 1, vector<int>(4, -1)));
        return getCount(alice, aliceScore, bobScore, 0, '!', dp) % mod;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/count-the-number-of-winning-sequences/
    */

    