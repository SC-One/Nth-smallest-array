#include <iostream>
#include <vector>
template <typename T>
int partition(std::vector<T>* vec,
              const std::pair<int, int> vecAlign) {  //[first,second)
                                                     //  print<T>(*vec);
  int result{vecAlign.first + 1};
  for (int i{vecAlign.first + 1}; i <= vecAlign.second; ++i) {
    if (vec->at(i) < vec->at(vecAlign.first)) {
      std::swap(vec->at(i), vec->at(result));
      result++;
    }
  }
  std::swap(vec->at(vecAlign.first), vec->at(--result));
  return result;
}

template <typename T>
T findMin(std::vector<T>* vec, int n, const std::pair<int, int> vecAlign) {
  int part = partition(vec, vecAlign);
  if (vecAlign.first > vecAlign.second) return vec->at(part);
  if (part < n) {
    n -= part;
    return findMin(vec, n, std::make_pair(part + 1, vecAlign.second));
  } else if (part > n) {
    return findMin(vec, n, std::make_pair(vecAlign.first, part - 1));
  } else
    return vec->at(part);
}

int main() {
  std::vector<int> temp{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << findMin<int>(&temp, 4, {0, temp.size() - 1});
  return 0;
}
