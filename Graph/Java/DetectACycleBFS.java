Problem Statement : Given an undirected Graph, check for a cycle using BFS (Breadth-First Search) Traversal.
Problem Link : https://takeuforward.org/data-structure/detect-a-cycle-in-undirected-graph-breadth-first-search/

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
       
            int V = 5;
            ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
            for(int i = 0; i < V; i++)
                adj.add(i, new ArrayList<Integer>());
                adj.get(0).add(1);
                adj.get(0).add(2);
                adj.get(2).add(3);
                adj.get(1).add(3);
                adj.get(2).add(4);

            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, adj);
            if(ans)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }


class Node {
    int first;
    int second;
    public Node(int first, int second) {
        this.first = first;
        this.second = second; 
    }
}
class Solution
{
   static boolean checkForCycle(ArrayList<ArrayList<Integer>> adj, int s,
            boolean vis[])
    {
       Queue<Node> q =  new LinkedList<>(); //BFS
       q.add(new Node(s, -1));
       vis[s] =true;
       
       while(!q.isEmpty())
       {
           int node = q.peek().first;
           int par = q.peek().second;
           q.remove(); 
           
           for(Integer it: adj.get(node))
           {
               if(vis[it]==false)  
               {
                   q.add(new Node(it, node));
                   vis[it] = true; 
               }
        
               else if(par != it) return true;
           }
       }
       
       return false;
    }
    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj)
    {
        boolean vis[] = new boolean[V];
        Arrays.fill(vis,false);
        for(int i=0;i<V;i++)
            if(vis[i]==false) 
                if(checkForCycle(adj, i,vis)) 
                    return true;
    
        return false;
    }
}

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.