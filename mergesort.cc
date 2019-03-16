#include <iostream>
#include <iterator>
#include <vector>

#include "mergesort.h"

// namespace mergesort {
// merges subarray of the array
template <typename RandomIt>
void merge(RandomIt Infirst, RandomIt Inmid, RandomIt Inlast,
           RandomIt Outfirst) {
  auto iterleft = Infirst;
  auto iterright = Inmid;
  auto iterout = Outfirst;

  while (iterleft != Inmid && iterright != Inlast) {
    if (*iterleft <= *iterright) {
      *iterout = *iterleft;
      ++iterleft;
    } else {
      *iterout = *iterright;
      ++iterright;
    }
    ++iterout;
  }
  while (iterleft != Inmid) {
    *iterout = *iterleft;
    ++iterleft;
    ++iterout;
  }
  while (iterright != Inlast) {
    *iterout = *iterright;
    ++iterright;
    ++iterout;
  }

  while (Infirst != Inlast) {
    *Infirst = *Outfirst;
    ++Infirst;
    ++Outfirst;
  }
}

template <typename RandomIt>
void sort(RandomIt Infirst, RandomIt Inlast, RandomIt Outfirst) {
  auto size = std::distance(Infirst, Inlast);
  if (size > 1) {
    auto mid = Infirst + size / 2 + size % 2;
    int dist = std::distance(Infirst, mid);

    sort(Infirst, mid, Outfirst);
    sort(mid, Inlast, Outfirst + dist);

    merge(Infirst, mid, Inlast, Outfirst);
  }
}

template <typename Container>
void mergesort(Container& List, Container& Out) {
  sort(List.begin(), List.end(), Out.begin());
}
/*
int main() {
  std::vector<int> list = {12, 4, 8, 1, 5, 32, 21, 0, 10, -2};
  std::vector<int> out(list.size());

  mergesort(list, out);

  for (int i = 0; i < out.size(); i++) {
    std::cout << out[i] << '\n';
  }
}
*/
//}  // namespace mergesort
