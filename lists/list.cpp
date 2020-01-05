#include <iostream>
#include <list>

int main(){
  std::list<int> ll{1,2,4};
  ll.push_front(0);
  ll.push_back(5);
  ll.insert(++++ll.begin(),3);
  for (auto& e :ll){
    std::cout << e << " ";
  }
}
