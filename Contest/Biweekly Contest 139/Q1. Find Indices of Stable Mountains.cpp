
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> res;
        for(int i = 1; i < height.size(); i++){
            if(height[i-1] > threshold) res.push_back(i);
        }
        return res;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/contest/biweekly-contest-139/problems/find-indices-of-stable-mountains/
    */

    
