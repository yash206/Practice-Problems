#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
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
}
