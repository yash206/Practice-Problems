// Problem Link : https://leetcode.com/problems/minimize-xor/


class Solution 
{
    public int minimizeXor(int num1, int num2) 
    {
      
      int x = countSetBits(num2);   
      x -= countSetBits(num1);  
      String ans = Integer.toString(num1,2);   
      StringBuilder str = new StringBuilder(ans);
      if(x==0)   
        return num1;
      
      if(x>0)
      {   
          int i=ans.length()-1;  least significant bit
         while(x!=0)
         {
           if(i<0)
           { 
             str.insert(0,'1');
             x--;
             continue;
           }
           if(str.charAt(i)!='1')
           { 
              str.setCharAt(i,'1'); 
              x--;
           }
           i--;     
        
         }
        
      }
    
      if(x<0)
      {  
          int i=ans.length()-1;
         while(x!=0)
         {
           
           if(str.charAt(i)!='0')
           {
              str.setCharAt(i,'0'); 
              x++;
           }
           i--;     
        
        }
        
      }
      
      return Integer.parseInt(str.toString(), 2);    
    }
  
  int countSetBits(int n)
    {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
}
