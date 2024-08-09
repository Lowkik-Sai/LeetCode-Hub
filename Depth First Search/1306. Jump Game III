
    /*
    Time complexity : O(N) - N is size of the given arr
    Space complexity : O(N) - For Visited arr of size N
    Recursion Stack Space : O(N) 
    */


class Solution {
public:
    bool reach(vector<int>& arr, int start, vector<bool>& visited) {
        if (start < 0 || start >= arr.size() || visited[start]) return false; 
        if (arr[start] == 0) return true; 

        visited[start] = true;
        bool left = reach(arr, start - arr[start], visited);
        bool right = reach(arr, start + arr[start], visited);

        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return reach(arr, start, vis);
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/jump-game-iii/
    */

    
