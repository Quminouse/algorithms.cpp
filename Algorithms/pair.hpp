template <typename X, typename Y> class Pair {
public:
  X first;
  Y second;

  Pair(X _first, Y _second);
  ~Pair();
};

template <typename X, typename Y> Pair<X, Y>::Pair(X _first, Y _second) {
  first = _first;
  second = _second;
}

template <typename X, typename Y> Pair<X, Y>::~Pair() {}
