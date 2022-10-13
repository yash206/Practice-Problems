#include <bits/stdc++.h>
using namespace std;
void printAns(vector<int> &arr, int n)
{
for (int i = 0; i < n; i++)
	cout << arr[i] << " ";
cout << endl;
}
void solve(vector<int> &arr, int n)
{
sort(arr.begin(),arr.end());
do {
printAns(arr, n);
} 
while(next_permutation(arr.begin(),arr.end()));
}
int main()
{
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++)
cin>>arr[i];
solve(arr,n);
return 0;
}

