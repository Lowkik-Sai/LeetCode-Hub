
    /*
    Time complexity : O(E * log V)
    Space complexity : O(E + V)
    */

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        map<int, vector<pair<int, int>>> graph;
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> dp(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;
        q.push({passingFees[0], {0, 0}});
        while(!q.empty()){
            int currFee = q.top().first;
            int currTime = q.top().second.first;
            int currEdge = q.top().second.second;
            q.pop();
            if(currEdge == n-1 && currTime <= maxTime) return currFee;
            if(currTime > maxTime) continue;
            if(dp[currEdge] <= currTime) continue;
            dp[currEdge] = currTime;
            for(int i = 0; i < graph[currEdge].size(); i++){
                q.push({currFee + passingFees[graph[currEdge][i].first], {currTime + graph[currEdge][i].second, graph[currEdge][i].first}});
            }
        }
        return -1;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
    */
