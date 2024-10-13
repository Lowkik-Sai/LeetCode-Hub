
    /*
    Time complexity : O(n * k * (k + log x))
    Space complexity : O(x + n)
    */


class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size()-k+1; i++){
            map<int, int> freq;
            for(int j = i; j <= i+k-1; j++){
                freq[nums[j]]++;
            }
            for(auto ele : freq){
                pq.push({ele.second, ele.first});
                if(pq.size() > x) pq.pop();
            }
            int sum = 0;
            while(!pq.empty()){
                sum += pq.top().first * pq.top().second;
                pq.pop();
            }
            res.push_back(sum);
        }
        return res;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
    */

    