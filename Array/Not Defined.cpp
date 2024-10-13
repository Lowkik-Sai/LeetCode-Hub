
    /*
    Time complexity : O(n * log n)
    Space complexity : O(1)
    */


class Solution {
public:
    int minElement(vector<int>& nums) {
        int minEle = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            int sumOfDig = 0;
            while(temp > 0){
                sumOfDig += temp % 10;
                temp /= 10;
            }
            minEle = min(minEle, sumOfDig);
        }
        return minEle;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
    */

    