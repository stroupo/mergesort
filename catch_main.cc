#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>
#include "mergesort.h"

using namespace Catch::Matchers;

TEST_CASE("Mergesort", "") {
  std::vector<int> liste = {54, 3, 1, 7, 4, 32, 9, 2};
  std::vector<int> out(liste.size());
  mergesort(liste, out);
  REQUIRE(liste[0] == 1);
  REQUIRE_THAT(liste, Vector::EqualsMatcher<int>({1, 2, 3, 4, 7, 9, 32, 54}));
}
