#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

/*
  Take the count of all the elements using a hash map. 
  Keep a size k min heap and keep replacing the top element if any other element has count more than it.
  Run Time Complexity => O(nlogk) => O(n) for the count, O(logk) for the min heap operations.
*/
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top().first << ", " << q.top().second << std::endl;
        q.pop();
    }
    //std::cout << '\n';
}

class compareGreater{
  public:
    bool operator()(std::pair<int, int> a, std::pair<int, int> b){
      return a.second > b.second;
    }
};

int main(){
  std::vector<int> vec{1,2,3,3,3,4,10,99,25,25,26,27,25,28};
  std::unordered_map<int, int> map;
  int k = 5;
  for(int i =0; i <vec.size(); ++i){
    if(map.find(vec[i]) != map.end()){
      ++map[vec[i]];
    }else{
      map[vec[i]] = 1;
    }
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compareGreater>  q;

  std::unordered_map<int, int>::const_iterator itr = map.begin();
  while(itr != map.end()){
//    std::cout << (itr)->first << ", " << (itr)->second << std::endl;
    if(q.size() < k){
      q.push(std::make_pair(itr->first, itr->second));
    }else{
      if(q.top().second < itr->second){
        q.pop();
        q.push(std::make_pair(itr->first, itr->second));
      }
    }
    ++itr;
  }
  print_queue(q); 
}
