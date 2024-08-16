
    /*
    Time complexity : O(n)
    Space complexity : O(1)
    */
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = INT_MIN;
        int minSoFar = arrays[0][0];
        int maxSoFar = arrays[0][arrays[0].size()-1];
        for(int i = 1; i < arrays.size(); i++){
            maxDist = max({maxDist, abs(maxSoFar - arrays[i][0]), abs(minSoFar - arrays[i][arrays[i].size()-1])});
            minSoFar = min(minSoFar, arrays[i][0]);
            maxSoFar = max(maxSoFar, arrays[i][arrays[i].size()-1]);
        }
        return maxDist;
    }
};
   /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16
    */
