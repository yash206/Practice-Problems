import java.util.Arrays;

// Problem link : https://leetcode.com/problems/super-ugly-number/


public class Solution
{
    public int nthSuperUglyNumber(int n, int[] primes) 
    {
        int k = primes.length;
        int[] p = new int[k];
        Arrays.fill(p, 0);
        int[] d = new int[n];
        d[0] = 1;
        for (int i = 1; i < n; i++) 
        {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < k; j++) 
            {
                min = Math.min(min, primes[j] * d[p[j]]);
            }

            d[i] = min;
            for (int j = 0; j < k; j++) 
            {
                if (primes[j] * d[p[j]] == min) 
                {
                    p[j] += 1;
                }
            }
        }
        return d[n-1];
    }
}