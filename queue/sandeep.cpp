#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> power,vector<int> mini,vector<int> maxi){

    int m = mini.size();
    int n = power.size();

    vector<vector<int>> data;
    for(int i=0;i<m;i++){data.push_back({mini[i],maxi[i],i});}

    sort(data.begin(),data.end());
    sort(power.begin(),power.end());

    vector<vector<int>> ans(m,vector<int>(2,0));

    int sum = 0;
    int start = 0;
    int end = 0;

    for(int i=0;i<m;i++){

        while(end < n && power[end] <= data[i][1]){
            sum += power[end];
            end++;
        }

        while(start < n && power[start] < data[i][0]){
            sum -= power[start];
            start++;
        }

        ans[data[i][2]][0] = end-start;
        ans[data[i][2]][1] = sum;

    }

    return ans;

}

int main(){

    int n;
    cin >> n;

    vector<int> power(n);
    for(int i=0;i<n;i++){cin >> power[i];}

    int m;
    cin >> m;

    vector<int> maxi(m);
    vector<int> mini(m);

    for(int i=0;i<m;i++){cin >> mini[i];}
    for(int i=0;i<m;i++){cin >> maxi[i];}

    vector<vector<int>> ans = solve(power,mini,maxi);

    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl ;
    }

    return 0;
}