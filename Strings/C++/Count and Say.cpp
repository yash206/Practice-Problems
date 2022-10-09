// Problem Link : https://leetcode.com/problems/count-and-say/


class Solution
{
  public:
    string lookandsay(int n)
    {
        string str = "1";
        int count = 1;
        string s = "";
        
        
        int i = 0;
        int j = 0;
       
       while(j<n-1){ 
        while(i<str.size())
        {
        while(i<str.size() && str[i+1]==str[i]){
            count++;
            i++;
        }
        s.push_back(count+48);
        s.push_back(str[i]);
        count = 1;
        i++;
        }
        str.clear();
        for(int i = 0; i<s.size(); i++)
        {
            str.push_back(s[i]);
        }
        s.clear();
        i = 0;
        j++;
    }
   
        return str;
                
    }   
};