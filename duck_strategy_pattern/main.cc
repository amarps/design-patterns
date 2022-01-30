#include "duck.hh"

void runDuck(const duck& d) {
  d.display();
  d.performFly();
  d.performQuack();

  std::cout << std::endl;
}

int main() {
  duck myduck;
  common_duck cduck;
  muted_rocket_duck mrduck;

  runDuck(myduck);
  runDuck(cduck);
  runDuck(mrduck);
}
