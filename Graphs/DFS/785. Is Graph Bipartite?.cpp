    /*
    Time complexity: O(V+N)
    Space complexity:O(N)
    */
class Solution {
public:
    bool colorNode(map<int, vector<int>>& list, int i, vector<int>& color, int parentColor){
        if (color[i] != -1) {
            return color[i] != parentColor;
        }
        color[i] = !parentColor;
        for(auto& it : list[i]){
            if(color[i] != -1) if(!colorNode(list, it, color, color[i])) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        map<int, vector<int>> list;
        for(int i = 0; i < graph.size(); i++){
            for(auto& j : graph[i]){
                list[i].push_back(j);
            }
        }
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                int parentColor = 1;
                if(!colorNode(list, i, color, parentColor)) return false;
            }
        }
        return true;
    }
};
    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/is-graph-bipartite/description/
    */
