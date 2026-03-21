// Copyright 2026 hyamamot

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = find(container.begin(), container.end(), value);
  if (it == container.end()) {
    throw std::exception();
  }
  return it;
}


