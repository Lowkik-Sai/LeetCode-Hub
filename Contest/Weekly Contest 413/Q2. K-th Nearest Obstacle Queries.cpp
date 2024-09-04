
    /*
    Time complexity : O(q logk)
    Space complexity : O(k)
    */
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> results;
        priority_queue<int> q;
        for(int i = 0; i < queries.size(); i++){
            if(q.size() >= k){
                if(i == 0 ||q.top() > abs(queries[i][0]) + abs(queries[i][1])){
                    q.pop();
                    q.push(abs(queries[i][0]) + abs(queries[i][1]));
                }
            }else{
                q.push(abs(queries[i][0]) + abs(queries[i][1]));
            }

            if(q.size() == k) results.push_back(q.top());
            else results.push_back(-1);
        }
        return results;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/contest/weekly-contest-413/problems/k-th-nearest-obstacle-queries/description/
    */

    
