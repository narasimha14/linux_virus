<<<<<<< HEAD
# first_repeated_word
# first_repeated_word
=======
# Shortest-Path-Algorithms
 *  This program contains implementations of shortest path algorithms viz. Dijkstra's and Bellman Ford
 *  Thanks to Dr. Brian Dean of Clemson University for the algorithms
 *  Below is the detailed description of the algorithms:
 *
 *  Tighten(i, j):
 *  1. If c[i] + cost(i, j) < c[j],
 *  2.    c[j] ← c[i] + cost(i, j)
 *  3.    b[j] ← i
 *
 *  Dijkstra(s):
 *  1. c[s] ← 0, c[i != s] ← +∞
 *  2. Add all nodes to a priority queue Q, keyed on the c[i]’s
 *  3. While Q is nonempty:
 *  4.    Remove from Q a node i having minimum label c[i]
 *  5.    Tighten all edges emanating from i
 *
 *  Bellman-Ford(s):
 *  1. c[s] ← 0, c[i != s] ← +∞
 *  2. Repeat n − 1 times:
 *  3.    Tighten every edge in the graph
 *  4. If c[i] + cost(i, j) < c[j] for any edge (i, j),
 *  5.    Output ‘Negative-Cost Directed Cycle Detected’
 *
 *  Time Complexity of Dijkstra depends on the structure used to implement the priority queue. 
 *  Implementation in this program uses a set (implemented using a self-balancing BST) thus running in O(mlogn) time.
 *  Time Complexity of Bellman-Ford is O(mn) where m -> number of edges and n -> number of vertices
>>>>>>> f80bbf6129f327ef881c93dcf35e9340f34be095
