#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
    int sum=0;
    int maxi=INT_MIN;
    for(auto it:nums){
        sum+=it;
        maxi=max(sum,maxi);
        if(sum<0)
        sum=0;
    }
    return maxi;
}


int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    int ans=solve(nums);
    cout<<ans<<endl;
    
}



// Find Maxiumum sum subarray using Kadane's Algorithm

/*
Input:-
5
-1 2 -3 -5 3

Output:-
3
*/
