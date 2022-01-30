#include <iostream>

class quack_behaviour {
public:
  virtual ~quack_behaviour() { }
  virtual void quack() = 0;
};

class quack_wekwek : public quack_behaviour {
public:
  void quack() override {
    std::cout << "im quacking wek wek wek" << std::endl;
  }
};

class quack_nono : public quack_behaviour {
public:
  void quack() {
    std::cout << "qrkwwasdiowafej duck diying" << std::endl;
  }
};
