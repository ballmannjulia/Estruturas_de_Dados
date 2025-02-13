#include "../include/linked_list.hpp"

int main(int argc, char const* argv[]) {
LinkedList<int> list;

list.push_front(10);
list.push_front(20);
list.push_front(30);
list.push_front(40);
list.push_front(50);

list.insert(2, 11);
list.insert(3, 12);
list.insert(7, 14);


list.print();
  return 0;
}
