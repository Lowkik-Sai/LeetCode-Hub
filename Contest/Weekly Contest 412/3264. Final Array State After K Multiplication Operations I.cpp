
    /*
    Time complexity: O(k * log n) (dominant for larger k)
    Space complexity: O(n)
    */
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(int i = 0; i < nums.size(); i++){
            q.push({nums[i], i});
        }
        for(int i = 1; i <= k; i++){
            auto [num, ind] = q.top();
            q.pop();
            q.push({num*multiplier, ind});
        }
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            auto [num, ind] = q.top();
            q.pop();
            ans[ind] = num;
        }
        return ans;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/contest/weekly-contest-412/problems/final-array-state-after-k-multiplication-operations-i/
    */
