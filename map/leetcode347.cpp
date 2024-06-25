#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<pair<int,int>> data ;
        int n = nums.size();
        map<int,int> temp ;
        
        for(int i=0;i<nums.size();i++){temp[nums[i]]++;}

        for(auto it : temp){data.push_back({it.second,it.first});}
        sort(data.begin(),data.end());

        vector<int> ans(k);
        for(int i=0;i<k;i++){ans[i] = data[data.size()-1-i].second;}

        return ans ;    

    }
};