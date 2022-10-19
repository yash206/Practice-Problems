// A C++ solution for longest palindrome substring.

// Problem Statement :- Given a string, find the longest substring which is a palindrome. 

/*
   Input: Given string :”forgeeksskeegfor”, 
   Output: Longest palindrome substring is: geeksskeeg and length is: 10 

   Input: Given string :”Geeks”, 
   Output: Longest palindrome substring is: ee and length is: 2
   
*/



#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s1) {
        if(s1.size() < 2)
            return s1;
        int k = 0, j = 0, i = 0, longest = 1, st = 0;
        while(k < s1.size() - longest/2){
            j = k;
            while(s1[k] == s1[k+1])
                ++k;
            i = k;
            while(k < s1.size() && j >0 && s1[k+1] == s1[j-1]){
                ++k;
                --j;
            }
            if(k-j+1 > longest){
                longest = k-j+1;
                st = j;
            }
            k = i + 1;
        }
        return s1.substr(st,longest);
    }

// Driver Code
int main()
{
    string str = "forgeeksskeegfor"; // Sample Input
    cout << longestPalindrome(str);
    // Output :- Longest palindrome substring is: geeksskeeg

    return 0;
}
