
    /*
    Time complexity: O(m^2 * n)
    Space complexity: O(m * n)
    */
class Solution {
public:
    int lines(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp, map<int, vector<int>>& n2){
        if(i >= nums1.size() || j >= nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxLines = 0;
        for(int i1 = i; i1 < nums1.size(); i1++){
            if(n2.find(nums1[i1]) != n2.end()){
                for(int j1 = 0; j1 < n2[nums1[i1]].size(); j1++){
                    if(n2[nums1[i1]][j1] < j) continue;
                    maxLines = max(maxLines, 1 + lines(nums1, nums2, i1+1, n2[nums1[i1]][j1] + 1, dp, n2));
                }
            }else continue;
        }
        return dp[i][j] = maxLines;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        map<int, vector<int>> n2;
        for(int i = 0; i < nums2.size(); i++){
            n2[nums2[i]].push_back(i);
        }
        return lines(nums1, nums2, 0, 0, dp, n2);
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/uncrossed-lines/
    */
