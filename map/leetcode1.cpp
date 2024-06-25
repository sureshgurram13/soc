#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> temp ;
        int n = nums.size();

        for(int i=0;i<n;i++){temp[nums[i]] = i+1;}

        for(int i=0;i<n;i++){
            if(temp[target-nums[i]] > 0 && i != temp[target-nums[i]]-1){
                return {i,temp[target-nums[i]]-1};
            }
        }

        return {-1,-1};

    }
};