
    /*
    Time complexity : O(n)
    Space complexity : O(n)
    */


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectComp(Node* left, Node* right){
        if(left && right){
            left->next = right;
            connectComp(left->right,right->left);
        }
    }
    void traverse(Node* left, Node* right){
        if(!left || !right) return ;
        left->next = right;
        traverse(left->left, left->right);
        traverse(right->left, right->right);
        connectComp(left->right, right->left);
    }

    Node* connect(Node* root) {
        if(!root) return root;
        traverse(root->left, root->right);
        return root;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
    */

    