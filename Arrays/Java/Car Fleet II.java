// Problem Link : https://leetcode.com/problems/car-fleet-ii/


class Solution 
{
    public double[] getCollisionTimes(int[][] cars) 
    {
        Deque<Integer> stack = new LinkedList<>();
        
        int n = cars.length;
        double[] ans = new double[n];
        
        for(int i = n - 1; i >= 0; i--) 
        {
            ans[i] = -1.0;
            
           
            int[] presentCar = cars[i];
            int presentCarPos = presentCar[0];
            int presentCarSpeed = presentCar[1];
            
            while(!stack.isEmpty()) 
            {
                
                int previousCar = stack.peekLast();
                int previousCarPos = cars[previousCar][0];
                int previousCarSpeed = cars[previousCar][1];
                eans that, when c2 (previous car) is trying to catch a car c3 in its front and takes (for ex 10 min) more time than the present car takes to catch previous car (for ex 5 min), then the present car will catch the previous car BEFORE the previous car catches c3
                if(presentCarSpeed > previousCarSpeed && (ans[previousCar] == -1.0 || catchTime(cars, i, previousCar) <= ans[previousCar])) {
                    ans[i] = catchTime(cars, i, previousCar);
                    break; 
                }
                
                
                stack.pollLast();
            }
            
            stack.offerLast(i);
        }
        
        return ans;
    }
   
    private double catchTime(int[][] cars, int presentCar, int previousCar) 
    {
        int dist = cars[previousCar][0] - cars[presentCar][0]; 
        int speed = cars[presentCar][1] - cars[previousCar][1]; 
        return 1.0 * dist/speed;
    }
}
