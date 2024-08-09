
    /*
    Time complexity : O(n) - n is size of the given arr
    Space complexity : O(2n)
    */


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxMountain = 0;
        vector<int> left(arr.size(), 0), right(arr.size() , 0);
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i-1]) left[i] = left[i-1] + 1;
        }
        for(int i = arr.size()-2; i >= 0; i--){
            if(arr[i] > arr[i+1]) right[i] = right[i+1] + 1;
        }
        for(int i = 0; i < arr.size(); i++){
            if(left[i] != 0 && right[i] != 0) maxMountain = max(maxMountain, left[i] + right[i] + 1);
        }
        return maxMountain >= 3 ? maxMountain : 0;
    }
};

    /*
    Time complexity : O(n^2) - n is size of the given arr
    Space complexity : O(1)
    */

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxMountain = 0;
        for(int i = 0; i < arr.size(); i++){
            int curr = arr[i];

            int left = 0;
            for(int j = i-1; j >= 0 && curr > arr[j]; j--){
                left += 1;
                curr = arr[j];
            }

            curr = arr[i];

            int right = 0;
            for(int j = i+1; j < arr.size() && curr > arr[j]; j++){
                right += 1;
                curr = arr[j];
            }
            maxMountain = (left != 0 && right != 0) ? max(maxMountain, left + right + 1) : maxMountain;
        }
        return maxMountain < 3 ? 0 : maxMountain;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/longest-mountain-in-array/
    */

    
