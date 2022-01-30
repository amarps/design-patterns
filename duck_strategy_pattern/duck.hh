#include <iostream>
#include <memory>
#include "fly_behaviour.hh"
#include "quack_behaviour.hh"

class duck {
public:
  virtual void display() const {
    std::cout << "im a duck" << std::endl;
  }
  
  void performQuack() const {
    if(mQuack_behaviour)
      mQuack_behaviour->quack();
  }

  void performFly() const {
    if (mFly_behaviour)
      mFly_behaviour->fly();
  }

protected:
  std::unique_ptr<fly_behaviour> mFly_behaviour = nullptr;
  std::unique_ptr<quack_behaviour> mQuack_behaviour = nullptr;
};

class common_duck : public duck {
public:
  void display() const override {
    std::cout << "just a common duck" << std::endl;
  }
  common_duck() {
    mFly_behaviour = std::unique_ptr<fly_behaviour>(new fly_nono{});
    mQuack_behaviour = std::unique_ptr<quack_behaviour>(new quack_wekwek{});
  }
};

class muted_rocket_duck :public duck {
public:
  void display() const override {
    std::cout << "im a mallard duck" << std::endl;
  }
  muted_rocket_duck() {
    mFly_behaviour = std::unique_ptr<fly_behaviour>(new fly_with_rocket{});
    mQuack_behaviour = std::unique_ptr<quack_behaviour>(new quack_nono{});
  }
};
