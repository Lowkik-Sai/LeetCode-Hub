
    /*
    Time complexity : O(V + ElogV)
    Space complexity : O(V + E)
    */


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        map<int, vector<pair<int, double>>> graph;
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> q;
        q.push({1, start_node});
        vector<double> dist(n, 0);
        dist[start_node] = 1;
        while(!q.empty()){
            auto [currProb, currNode] = q.top();
            q.pop();
            if(currNode == end_node){
                return currProb;
            }

            for(auto i : graph[currNode]){
                double newProb = currProb * i.second;
                if(newProb > dist[i.first]){
                    q.push({newProb, i.first});
                    dist[i.first] = newProb;
                }
            }
        }

        return 0;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/path-with-maximum-probability/
    */

    
