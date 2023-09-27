#include <assert.h>

template <typename T> class Option {
private:
  bool some;
  T data;

public:
  Option(T _data);
  Option();
  ~Option();

  T unwrap();

  bool is_some();
  bool is_none();
};

template <typename T> Option<T>::Option() { some = false; }

template <typename T> Option<T>::Option(T _data) {
  some = true;
  data = _data;
}

template <typename T> Option<T>::~Option() {}

template <typename T> T Option<T>::unwrap() {
  if (some) {
    return data;
  }
  assert(("TRIED TO UNWRAP NONE OPTION", 0));
}

template <typename T> bool Option<T>::is_none() { return !some; }
template <typename T> bool Option<T>::is_some() { return some; }
