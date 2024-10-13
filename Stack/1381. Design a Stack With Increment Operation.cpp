
    /*
    Time complexity : push and pop functions: O(1)
increment function: O(min(k, maxSize))
    Space complexity : O(maxSize)
    */


class CustomStack {
private:
    vector<int> st;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxSize) {
            st.push_back(x);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int poppedVal = st.back();
        st.pop_back();
        return poppedVal;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)st.size()); 
        for(int i = 0; i < k; i++) {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/design-a-stack-with-increment-operation/
    */

    