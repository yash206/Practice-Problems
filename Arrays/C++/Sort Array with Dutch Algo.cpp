#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
        
            if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
            }
            
            else if(nums[mid]==1)
            mid++;
           
            
            else{
            swap(nums[mid],nums[high]);
            high--;
            }
            
        
    }
    }

void printAns(vector<int> &nums){
    for(int i=0;i<nums.size();i++)
    cout<<nums[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    cin>>nums[i];
    sortColors(nums);
    printAns(nums);
}

// Sort Array containing 0s,1s, and 2s using Dutch national Flag Algo

/*
Input:-
5
2 1 1 0 2

Output:-
0 1 1 2 2
*/