#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>
#include <list>

template <class T> using uptr = std::unique_ptr<T>;
template <class T> using sptr = std::shared_ptr<T>;
template <class T> using v_uptr = std::vector<std::unique_ptr<T>>;

class observer {
public:
  virtual void update(int updatedData) = 0;
};

class subject {
public:
  virtual void registerObserver(observer *o) = 0;
  virtual void removeObserver(observer *o) = 0;
  virtual void notifyObserver() = 0;
};

class weather_data : public subject {
public:
  v_uptr<observer> observers;
  virtual void registerObserver(observer *o) override {
    observers.push_back(uptr<observer>(std::move(o)));
  }
  virtual void removeObserver(observer *o) override {
    auto temp_it = observers.begin();
    for (; temp_it != observers.end(); ++temp_it) {
      if (temp_it->get() == o)
	break;
    }

    observers.erase(temp_it);
  }
  virtual void notifyObserver() override {
    for (auto &o : observers) {
      o->update(mTemperature);
    }
  }

  int mTemperature = 0;
};

class current_condition_display : public observer {
  uptr<subject> mWeatherData;
public:
  current_condition_display(subject *pWeatherData) :mWeatherData(std::move(pWeatherData)) {}
  void update(int updatedData) {
    data = updatedData;
  }

  int data = 0;
};

class predict_tomorow : public observer {
  uptr<subject> mWeatherData;
public:
  predict_tomorow(subject *pWeatherData) :mWeatherData(std::move(pWeatherData)) {}
  void update(int updatedData) {
    data = updatedData;
    data = (data * 2);
  }

  int data = 0;
};

class statistic_display : observer {
public:
  void update(int updatedData) {
    data = updatedData;
  }

  int data = 0;
};

int main(void) {
  uptr<subject> weatherData = uptr<subject>(new weather_data);
  uptr<observer> currentDisplay =
      uptr<observer>(new current_condition_display(weatherData.get()));
  uptr<observer> predicttomorrowdisplay =
      uptr<observer>(new predict_tomorow(weatherData.get()));
  dynamic_cast<weather_data*>(weatherData.get())->mTemperature = 3;
  weatherData->registerObserver(currentDisplay.get());
  weatherData->registerObserver(predicttomorrowdisplay.get());
  weatherData->notifyObserver();

  std::cout
      << dynamic_cast<current_condition_display *>(currentDisplay.get())->data
      << std::endl;
  std::cout << dynamic_cast<predict_tomorow *>(predicttomorrowdisplay.get())->data
            << std::endl;
}
