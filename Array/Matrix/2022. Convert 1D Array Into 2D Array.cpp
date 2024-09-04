
    /*
    Time complexity : O(m * n)
    Space complexity : Om * n)
    */

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        int ind = 0;
        vector<vector<int>> twoDarr;
        for(int i = 0; i < m; i++){
            vector<int> oneDarr;
            for(int j = 0; j < n; j++){
                oneDarr.push_back(original[ind++]);
            }
            twoDarr.push_back(oneDarr);
        }
        return twoDarr;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/convert-1d-array-into-2d-array/description/
    */

    
