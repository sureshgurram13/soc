#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:

    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;

    int s1,s2;

    MedianFinder() {
        s1 = s2 = 0;
    }
    
    void addNum(int num) {
        
        if(q1.size() == 0 || q1.top() >= num){
            q1.push(num);
            s1++;
        }
        else{
            q2.push(num);
            s2++;
        }

        if(s1 - s2 > 1){
            q2.push(q1.top());
            q1.pop();
            s1--;
            s2++;
        }

        if(s2 - s1 > 1){
            q1.push(q2.top());
            q2.pop();
            s1++;
            s2--;
        }

    }
    
    double findMedian() {
        if(s1 == s2){
            return double(q1.top()+q2.top())/2 ;
        }else if(s1 > s2){
            return q1.top();
        }else{
            return q2.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */