#include "duck.hh"
#include <iostream>

extern std::ostream &operator<<(std::ostream &out, const duck_can_show &obj);

int main(void) {
  duck just_duck;
  std::cout << just_duck;

  mallard_duck mall_duck;
  std::cout << mall_duck;

  redhead_duck red_duck;
  std::cout << red_duck;
}
