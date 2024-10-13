
    /*
    Time complexity : O(n)
    Space complexity : Not Defined
    */


class MyCalendar {
public:
    vector<pair<int, int>> intervals;

    MyCalendar() {
        
    }
    
    bool book(int x, int y) {
        for(int i = 0; i < this->intervals.size(); i++){
            int a = this->intervals[i].first, b = this->intervals[i].second;
            if((a < y && b > x) || (x < b && y > a) || (a <= x && y <= b) || (x<a && b<y)) {
                return false;
            }
        }
        
        this->intervals.push_back({x, y});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/my-calendar-i/
    */

    