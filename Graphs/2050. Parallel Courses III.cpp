
    /*
    Time complexity : O(V + E)
    Space complexity : O(V + E)
    */


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        map<int, vector<int>> relate;
        vector<int> inDeg(n, 0);
        for(int i = 0; i < relations.size(); i++){
            relate[relations[i][0]-1].push_back(relations[i][1]-1);
            inDeg[relations[i][1]-1] += 1;
        }
        queue<int> q;
        vector<int> dist(n, -1e9);
        for(int i = 0; i < n; i++){
            if(!inDeg[i]){
                q.push(i);
                dist[i] = time[i];
            }
        }
        int totMonths = -1e9;
        while(!q.empty()){
            int currCourse = q.front();
            q.pop();

            totMonths = max(totMonths, dist[currCourse]);

            for(auto j : relate[currCourse]){
                inDeg[j] -= 1;
                if(!inDeg[j]) q.push(j); 
                dist[j] = max(dist[j], dist[currCourse] + time[j]);
            }
            
        }
        return totMonths;

    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/parallel-courses-iii/
    */

    