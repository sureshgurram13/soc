#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> greater(10001,-1);

        stack<int> temp;
        int m = nums2.size();

        for(int i=0;i<m;i++){

            while(temp.size() != 0 && temp.top() < nums2[i]){
                greater[temp.top()] = nums2[i];
                temp.pop();
            }

            temp.push(nums2[i]);

        }

        while(temp.size() != 0){
            greater[temp.top()] = -1;
            temp.pop();            
        }
        
        for(int i=0;i<nums1.size();i++){nums1[i] = greater[nums1[i]];}

        return nums1;

    }
};