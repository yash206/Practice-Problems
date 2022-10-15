#include<iostream>
using namespace std;
int findpivot(int arr[],int n){
    int s=0,e=n-1;
    int ans=-1;
    int mid=s+(e-s)/2;
    while (s<e)
    {
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return mid;
}
int main(){
int arr[5]={7,9,1,2,3};  //Sample input.
int a=findpivot(arr,5);
cout<<a<<endl;   // Output for sample input will be 2.
return 0;
}