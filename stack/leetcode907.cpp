#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int sumSubarrayMins(vector<int>& arr) {

        long long int ans = 0 ;
        int n = arr.size();

        stack<int> temp ;
        vector<long long> left(n,-1);

        for(int i=0;i<n;i++){

            while(temp.size() != 0 && arr[temp.top()] > arr[i]){temp.pop();}

            if(temp.size() == 0){left[i] = i;}
            else{left[i] = i-temp.top()-1;}

            temp.push(i);

        }

        while(temp.size() != 0){temp.pop();}
        vector<long long> right(n,-1);

        for(int i=n-1;i>=0;i--){

            while(temp.size() != 0 && arr[temp.top()] >= arr[i]){temp.pop();}

            if(temp.size() == 0){right[i] = n-1-i;}
            else{right[i] = temp.top()-i-1;}

            temp.push(i);

        }

        for(int i=0;i<n;i++){
            long long temp = (left[i]+1)*(right[i]+1)*arr[i] ;
            ans += temp ;
            ans = ans % 1000000007;
        }

        return ans ;
        
    }
};