//Connect n ropes into one rope with minimum cost such that the cost to connect two ropes is sum of their lengths
//For Ex - Given n ropes and array contains length of each rope, n =4 and arr[] = {4, 3, 2, 6}
// Output -> 29     Cost = 5 + 9 + 15 = 29 (Taking two small elements and add them)
import java.util.*;
public class ConnectRopes {
    public static void main(String[] args){                                    //main function
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();                                                   //taking inputs
        int arr[] = new int[n];
        for(int i =0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(minCost(arr,n));
    }

    static int minCost(int[] arr, int n){
        PriorityQueue<Integer> pq = new PriorityQueue<>();          //Creating a priority queue
        for(int i=0; i<n;i++){                                      //Adding elements to the queue
            pq.add(arr[i]);
        }
        int ans = 0;
        while(pq.size() > 1){                               //While there is atleast two elements in qeueue
            int first = pq.poll();                      //Getting two smaller ropes
            int second = pq.poll();
            int sum = first + second;                   //Connect two ropes and update result
            ans += sum;
            pq.add(sum);
        }
        return ans;
    }
}


//Time Complexity -> O(nlogn)
//Space Complexity -> O(n)