
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */
class Solution {
public:
    int calculateSubTreeSizes(map<int, vector<int>>& tree, vector<int>& subTreeSize, int node) {
        subTreeSize[node] = 1;
        
        for (int child : tree[node]) {
            subTreeSize[node] += calculateSubTreeSizes(tree, subTreeSize, child);
        }
        
        return subTreeSize[node];
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = 0;
        map<int, vector<int>> tree;
        int flag1 = 0;
        for(int i = 0; i < edges.size(); i++){
            tree[edges[i][0]].push_back(edges[i][1]);
            if(edges[i][1] == 0) flag1 = 1;
            n = max({n, edges[i][0], edges[i][1]});
        }
        if(flag1) {
            tree.clear();
            for(int i = 0; i < edges.size(); i++){
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        }
        n += 1;
        int count = 0;
        vector<int> subTree(n, 0);
        calculateSubTreeSizes(tree, subTree, 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(!tree[curr].size()){
                count += 1;
            }
            else {
                int flag = 1;
                for(int child = 0; child < tree[curr].size(); child++){
                    if(child < tree[curr].size()-1 && subTree[tree[curr][child]] != subTree[tree[curr][child+1]]) flag = 0;
                    q.push(tree[curr][child]);
                }
                if(flag) count += 1;
            }
        }
        return count;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/count-the-number-of-good-nodes/description/
    */

    
