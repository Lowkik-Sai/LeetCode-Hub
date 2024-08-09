
    /*
    Time complexity : O(N^2) - N is size of the given arr
    Space complexity : O(N^2)
    */

//Tabulation Method :
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLength = 0;
        vector<vector<int>> dp(arr.size(), vector<int> (arr.size(), 2));
        unordered_map<int, int> mapping;
        for(int i = 0; i <= arr.size() - 1; i++) mapping[arr[i]] = i;
        for(int i = 0; i <= arr.size() - 1; i++){
            for(int prev = 0; prev < i; prev++){
                int target = arr[i] - arr[prev];
                if(mapping.find(target) != mapping.end() && prev > mapping[target]){
                    dp[i][prev] = max(dp[i][prev], dp[prev][mapping[target]] + 1);
                }
                maxLength = max(maxLength, dp[i][prev]);
            }
        }
        if(maxLength == 0) return maxLength;
        return maxLength + 2; 
    }
};

//Memoized Method :
// class Solution {
// public:
//     int fibSeq(vector<int>& arr, vector<vector<int>>& dp, int i, int prev, int& maxLength, map<int, int>& mapping){
//         if (prev < 0) return 0;  
//         if (dp[i][prev] != -1) return dp[i][prev]; 

//         dp[i][prev] = 2;

//         int target = arr[i] - arr[prev];
//         if (mapping.find(target) != mapping.end() && mapping[target] < prev) {
//             dp[i][prev] = fibSeq(arr, dp, prev, mapping[target], maxLength, mapping) + 1;
//         }

//         maxLength = max(maxLength, dp[i][prev]);

//         return dp[i][prev];
//     }

//     int lenLongestFibSubseq(vector<int>& arr) {
//         int maxLength = 0;
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         map<int, int> mapping;

//         for (int i = 0; i < n; i++) mapping[arr[i]] = i;

//         for (int i = 0; i < n; i++) {
//             for (int j = i - 1; j >= 0; j--) {
//                 fibSeq(arr, dp, i, j, maxLength, mapping);
//             }
//         }

//         return maxLength > 2 ? maxLength : 0;  
//     }
// };


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
    */

    
