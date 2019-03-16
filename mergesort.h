#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <iterator>
#include <vector>

// namespace mergesort {
// merges subarray of the array
template <typename RandomIt>
void merge(RandomIt Infirst, RandomIt Inmid, RandomIt Inlast,
           RandomIt Outfirst);

template <typename RandomIt>
void sort(RandomIt Infirst, RandomIt Inlast, RandomIt Outfirst);

template <typename Container>
void mergesort(Container& List, Container& Out);

//}  // namespace mergesort

// using namespace mergesort

#endif /* end of include guard: MERGESORT_H */
