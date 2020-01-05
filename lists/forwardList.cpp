#include <forward_list>
#include <iostream>

int main() {
  std::forward_list<int> l{1,2,4};
  l.push_front(0);
  l.insert_after(++++l.begin(), 3);

  for ( auto& e : l  )
        std::cout << e << " ";

  // print 1 2 3 4
}
