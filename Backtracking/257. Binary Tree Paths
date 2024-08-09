
    /*
    Time complexity : O(N) - N is number of nodes in given Binary Tree
    Space complexity : O(L) - L is total maxLength of the string in that path
    Recursion Stack Space : O(N) - N is number of nodes in given Binary Tree
    */


 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void getAllPaths(TreeNode* root, string& curr, vector<string>& paths){
        if(!root->left && !root->right){
            paths.push_back(curr);
            return ;
        }
        if(root->left){
            curr += "->" + (to_string)(root->left->val);
            getAllPaths(root->left, curr, paths);
            for(int i = 1; i <= (to_string)(root->left->val).size() + 2; i++){
                curr.pop_back();
            }
        }
        if(root->right){
            curr += "->" + (to_string)(root->right->val);
            getAllPaths(root->right, curr, paths);
            for(int i = 1; i <= (to_string)(root->right->val).size() + 2; i++){
                curr.pop_back();
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string curr;
        vector<string> paths;
        curr += (to_string) (root->val);
        getAllPaths(root, curr, paths);
        return paths;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/binary-tree-paths/
    */

    
