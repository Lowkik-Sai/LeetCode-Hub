
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


    /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> levelOrder;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> curr;
            for(int i = 1; i <= size; i++){
                Node* node = q.front();
                q.pop();
                for(auto& j : node->children){
                    q.push(j);
                }
                curr.push_back(node->val);
            }
            levelOrder.push_back(curr);
        }
        return levelOrder;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/n-ary-tree-level-order-traversal/
    */

    
