#include <iostream>

struct LinkedList
{
  int head;
  LinkedList* tail = nullptr;
};


void traversal(LinkedList const& head) {
  std::cout << head.head;
  if ( head.tail != nullptr )
  {
    std::cout << "->";
    traversal(*head.tail);
  }
  else
  {
    std::cout << std::endl;
  }
}
int main ()
{
  LinkedList n1;
  n1.head = 3;
  LinkedList n2;
  n2.head = 2;
  n2.tail = &n1;
  LinkedList n3;
  n3.head = 1;
  n3.tail = &n2;
  traversal(n3);

}
