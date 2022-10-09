//There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
//Given the array answers, return the minimum number of rabbits that could be in the forest.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
    class Solution
    {
    public:
        int numRabbits(vector<int> &answers)
        {
            int counts = 0;
            unordered_map<int, int> m;
            for (int i = 0; i < answers.size(); i++)
            {
                m[answers[i]] = count(answers.begin(), answers.end(), answers[i]);
            }
            for (auto val : m)
            {
                if (val.first == 0)
                {
                    counts = counts + val.second;
                }
                else if (val.second % (val.first + 1) == 0)
                {
                    int a = val.second / (val.first + 1);
                    counts = counts + a * (val.first + 1);
                }
                else
                {
                    int q = val.second % (val.first + 1);
                    int b = val.second - q;
                    counts = counts + val.first + 1;
                    counts = counts + b;
                }
            }

            return counts;
        }
    };
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    Solution s1;
    cout<<"The number of rabbits in the forrest will be " <<s1.numRabbits(v)<<endl;
    
    return 0;
}


/*input : 5
          1 4 2 1 1
output : The number of rabbits in the forest will be 12

explaination : 1st rabbit is saying that there is one rabbit like me and in in the array 4th rabbit is saying there is one rabbit like me , so both can be equal 1+1=2
                 2st rabbit is saying that there are four rabbits like me and in array no one is saying same hence 4+1=5
                 3rt rabbit is saying that there two rabbit like me and and in array no one is saying same hence 2+1=3
                 5st rabbit is saying that there is one rabbit like me and in in the array no one is saying same (since 1st and 4th rabbit cancel out in first case) hence 1+1=2
                 
                 therefore , ans is 2+5+3+2=12  */
