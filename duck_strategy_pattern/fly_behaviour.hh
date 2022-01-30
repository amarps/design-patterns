#include <iostream>

class fly_behaviour {
public:
  virtual ~fly_behaviour() {}
  virtual void fly() = 0;
};

class fly_with_rocket : public fly_behaviour {
public:
  void fly() override {
    std::cout << "brrrrr im flying with rocket"
	      << std::endl;
  }
};

class fly_nono : public fly_behaviour {
public:
  void fly() override {
    std::cout << "i can't fly." << std::endl;
  }
};
