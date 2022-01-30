#include <string>
#include <sstream>

class duck_can_show {
public:
  virtual std::string show() const = 0;
};

class duck_behaviour {
public:
  std::string quack() const {
    std::stringstream msg;
    msg << "Duck quacking: " << mQuack_sound << std::endl;
    return msg.str();
  }

  std::string swim() const {
    std::stringstream msg;
    msg << "Duck Swimming: " << mSwim_sound << std::endl;
    return msg.str();
  }

private:
  std::string mQuack_sound = "wek wek wek wek";
  std::string mSwim_sound = "brrrr ";
};

class duck : duck_behaviour, public duck_can_show {
public:
  virtual std::string show() const override{
    std::stringstream show_msg;
    show_msg << "Im duck\n" << swim() << quack();
    return show_msg.str();
  }
};

class mallard_duck : duck_behaviour,
                     public duck_can_show {
public:
  std::string show() const override {
    std::stringstream show_msg;
    show_msg << "Im mallard duck\n" << swim() << quack();
    return show_msg.str();
  }
};

class redhead_duck : duck_behaviour,
                     public duck_can_show {
public:
  std::string show() const override {
    std::stringstream show_msg;
    show_msg << "Im Red Head duck\n" << swim() << quack();
    return show_msg.str();
  }
};

extern std::ostream &operator<<(std::ostream &out, const duck_can_show &obj) {
  out << "Duck show: " << obj.show() << std::endl;
  return out;
}
