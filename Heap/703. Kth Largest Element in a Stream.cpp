
    /*
    Time complexity : O(klogk) - k is max size of the heap
    Space complexity : O(k) - Storing max k elements at a instance
    */

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> arr;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (arr.size() < k) {
            arr.push(val);
        } else if (val > arr.top()) {
            arr.pop();
            arr.push(val);
        }
        return arr.top();
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/kth-largest-element-in-a-stream/
    */

