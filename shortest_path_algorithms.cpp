#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <climits>
#include <ctime>

/**
 *  @author: Narasimha Murthy
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
 *
 * */


// edges[i] contain all directed edges emanating from i and it's associated cost
std::vector<int> dijkstra(int src, std::vector< std::vector< std::pair<int, int> > >& edges, std::vector<int>& vertices){
  std::clock_t start;
  start = std::clock();
  std::set< std::pair<int, int> > pq;
  std::vector<int> cost;
  // Initialise cost of src to zero and all others to +infinity
  for(int i=0; i < vertices.size(); ++i){
    if(vertices[i] == src)
      cost.push_back(0);
    else
      cost.push_back(INT_MAX);
    pq.insert(std::make_pair(cost[i], vertices[i]) );
  }

  //Remove nodes from priority queue one by one starting with the minimum
  while(! pq.empty()){
    std::pair<int, int> first_node = *(pq.begin());
    pq.erase(pq.begin());

    int node = first_node.second;
  
    for(int i =0; i < edges[node].size();++i){
      int edge_cost = edges[node][i].second;
      int edge_node = edges[node][i].first;
      if( cost[node] + edge_cost < cost[edge_node]){
        pq.erase(pq.find(std::make_pair(cost[edge_node], edge_node)));
        cost[edge_node] = cost[node] + edge_cost;
        pq.insert(std::make_pair(cost[edge_node], edge_node) );
      }
    }

  }
  std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
  return cost;
}

// Overloaded method to get the actual path along with the cost
std::vector<int> dijkstra(int src, std::vector< std::vector< std::pair<int, int> > >& edges, std::vector<int>& vertices, std::vector<int>& parent){
  std::clock_t start;
  start = std::clock();
  std::set< std::pair<int, int> > pq;
  std::vector<int> cost;
  parent[0] = 0;
  // Initialise cost of src to zero and all others to +infinity
  for(int i=0; i < vertices.size(); ++i){
    if(vertices[i] == src)
      cost.push_back(0);
    else
      cost.push_back(INT_MAX);
    pq.insert(std::make_pair(cost[i], vertices[i]) );
  }

  //Remove nodes from priority queue one by one starting with the minimum
  while(! pq.empty()){
    std::pair<int, int> first_node = *(pq.begin());
    pq.erase(pq.begin());

    int node = first_node.second;
  
    for(int i =0; i < edges[node].size();++i){
      int edge_cost = edges[node][i].second;
      int edge_node = edges[node][i].first;
      if( cost[node] + edge_cost < cost[edge_node]){
        pq.erase(pq.find(std::make_pair(cost[edge_node], edge_node)));
        cost[edge_node] = cost[node] + edge_cost;
        parent[edge_node] = node;
        pq.insert(std::make_pair(cost[edge_node], edge_node) );
      }
    }

  }
  std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
  return cost;
}

std::vector<int> bellman_ford(int src, std::vector< std::vector<std::pair<int, int> > >& edges, std::vector<int>& vertices){
  std::clock_t start;
  start = std::clock();
  std::vector<int> cost;
  for(int i=0; i < vertices.size(); ++i){
    if(vertices[i] == src)
      cost.push_back(0);
    else
      cost.push_back(INT_MAX);
  }

  for(int i=0; i < vertices.size() -1; ++i){
    for(int j=0; j < edges.size(); ++j){
      for(int k=0; k < edges[j].size(); ++k){ 
        int second_node = edges[j][k].first;
        int edge_cost = edges[j][k].second;

        if( cost[j] + edge_cost < cost[second_node]){
          cost[second_node] = cost[j] + edge_cost;
        }
      }
    }
  }
  std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
  return cost;
}

// Overloaded method to get the actual path along with the cost
std::vector<int> bellman_ford(int src, std::vector< std::vector<std::pair<int, int> > >& edges, std::vector<int>& vertices, std::vector<int>& parent){
  std::clock_t start;
  start = std::clock();
  std::vector<int> cost;
  parent[0] = 0;
  for(int i=0; i < vertices.size(); ++i){
    if(vertices[i] == src)
      cost.push_back(0);
    else
      cost.push_back(INT_MAX);
  }

  for(int i=0; i < vertices.size() -1; ++i){
    for(int j=0; j < edges.size(); ++j){
      for(int k=0; k < edges[j].size(); ++k){ 
        int second_node = edges[j][k].first;
        int edge_cost = edges[j][k].second;

        if( cost[j] + edge_cost < cost[second_node]){
          cost[second_node] = cost[j] + edge_cost;
          parent[second_node] = j;
        }
      }
    }
  }
  std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
  return cost;
}

// Method to print edges in the form of A ---- wt(A,B)---> B
void printEdges(std::vector< std::vector< std::pair<int, int> > > edges){
  std::cout << "Edges:" << std::endl;
  for(int i=0; i < edges.size(); ++i){
    for(int j=0; j < edges[i].size(); ++j){
      std::cout << i << " --- " << edges[i][j].second << " ---> " << edges[i][j].first << std::endl ;
    }
  }
}

// Method to print the shortest path
void printPath(int dest, std::vector<int>& parent){
  std::cout << "Shortest path from 0 to " << dest << ":\t"; //<< std::endl;
  std::stack<int> st;
  st.push(dest);
  for(int i = dest; i > 0; i = parent[i]){
    st.push(parent[i]);
  }
  while(st.size() > 1){
    std::cout << st.top() << "->";
    st.pop();
  }
  std::cout << st.top() << std::endl;
  st.pop();
}

int main(){
  std::vector< std::vector< std::pair<int, int> > > edges;
  edges.reserve(9);
  std::vector< std::pair<int, int> > toAdd;
  toAdd.push_back( std::make_pair(1,4));
  toAdd.push_back( std::make_pair(7,8));
  edges.push_back(toAdd);
  toAdd.clear();
  toAdd.push_back( std::make_pair(2,8));
  toAdd.push_back( std::make_pair(7,11));
  edges.push_back(toAdd);
  toAdd.clear();
  toAdd.push_back( std::make_pair(3,7));
  toAdd.push_back( std::make_pair(8,2));
  toAdd.push_back( std::make_pair(5,4));
  edges.push_back(toAdd);
  toAdd.clear();
  toAdd.push_back( std::make_pair(4,9));
  toAdd.push_back( std::make_pair(5,14));
  edges.push_back(toAdd);
  toAdd.clear();
  toAdd.push_back( std::make_pair(5,10));
  edges.push_back(toAdd);
  toAdd.clear();
  toAdd.push_back( std::make_pair(6,2));
  edges.push_back(toAdd);
  toAdd.clear();
  toAdd.push_back( std::make_pair(7,1));
  toAdd.push_back( std::make_pair(8,6));
  edges.push_back(toAdd);
  toAdd.clear();
  toAdd.push_back( std::make_pair(8,7));
  edges.push_back(toAdd);
  toAdd.clear();
  
  std::vector<int> vertices{0,1,2,3,4,5,6,7,8};
  std::vector<int> cost, parent;

  printEdges(edges);

  std::cout << "Dijkstra:" << std::endl;
  cost = dijkstra(0, edges, vertices);

  for(int i=0; i < cost.size(); ++i){
    std::cout << "Cost from 0 to " << i << " is " << cost[i] << std::endl; 
  }

  // Print the path
  parent.reserve(vertices.size());
  cost.clear();
  std::cout << "Dijkstra with backtracking:" << std::endl;
  cost = dijkstra(0, edges, vertices, parent);

  for(int i =0; i < vertices.size(); ++i){
    printPath(vertices[i], parent);
  }
  // Print the path

  cost.clear();
  parent.clear();
  std::cout << "Bellman Ford:" << std::endl;
  cost = bellman_ford(0, edges, vertices); 
  for(int i=0; i < cost.size(); ++i){
    std::cout << "Cost from 0 to " << i << " is " << cost[i] << std::endl; 
  }
  
  // Print the path
  cost.clear();
  std::cout << "Bellman Ford with backtracking:" << std::endl;
  cost = bellman_ford(0, edges, vertices, parent); 
  for(int i =0; i < vertices.size(); ++i){
    printPath(vertices[i], parent);
  }
  // Print the path
  
  return 0;
  
}

