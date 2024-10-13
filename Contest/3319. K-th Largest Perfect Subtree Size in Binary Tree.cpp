
    /*
    Time complexity : O(n * log n)
    Space complexity : O(log n + k)
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
    vector<int> calcPerfectSubtree(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& sizes, int& k){
        if(!root) return {1,0};

        vector<int> left = calcPerfectSubtree(root->left, sizes, k);
        vector<int> right = calcPerfectSubtree(root->right, sizes, k);
        if(!left[0] || !right[0]) return {0,0};

        if(left[1] == right[1]){
            sizes.push(left[1]+right[1]+1);
            if(sizes.size() > k) sizes.pop();
        }
        return {left[1] == right[1] , left[1]+right[1]+1};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> sizes;
        calcPerfectSubtree(root, sizes, k);
        return sizes.size() != k ? -1 : sizes.top();
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/
    */

    