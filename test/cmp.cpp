#include "cmp_header.hpp"

// comparisons between [1,2] and [3,4]

static void test_12_34() {
  const I a(1,2), b(3,4);

  BOOST_CHECK(a < b);
  BOOST_CHECK(a <= b);
  BOOST_CHECK(!(a > b));
  BOOST_CHECK(!(a >= b));

  BOOST_CHECK(b > a);
  BOOST_CHECK(b >= a);
  BOOST_CHECK(!(b < a));
  BOOST_CHECK(!(b <= a));

  BOOST_CHECK(!(a == b));
  BOOST_CHECK(a != b);
}

// comparisons between [1,3] and [2,4]

static void test_13_24() {
  const I a(1,3), b(2,4);

  BOOST_C_EXN(a < b);
  BOOST_C_EXN(a <= b);
  BOOST_C_EXN(a > b);
  BOOST_C_EXN(a >= b);

  BOOST_C_EXN(b < a);
  BOOST_C_EXN(b <= a);
  BOOST_C_EXN(b > a);
  BOOST_C_EXN(b >= a);

  BOOST_C_EXN(a == b);
  BOOST_C_EXN(a != b);
}

// comparisons between [1,2] and [2,3]

static void test_12_23() {
  const I a(1,2), b(2,3);

  BOOST_C_EXN(a < b);
  BOOST_CHECK(a <= b);
  BOOST_CHECK(!(a > b));
  BOOST_C_EXN(a >= b);

  BOOST_CHECK(!(b < a));
  BOOST_C_EXN(b <= a);
  BOOST_C_EXN(b > a);
  BOOST_CHECK(b >= a);

  BOOST_C_EXN(a == b);
  BOOST_C_EXN(a != b);
}

static void test_12_E() {
  I a(1, 2), b(I::empty());
  
  BOOST_C_EXN(a < b);
  BOOST_C_EXN(a <= b);
  BOOST_C_EXN(a > b);
  BOOST_C_EXN(a >= b);

  BOOST_C_EXN(b < a);
  BOOST_C_EXN(b <= a);
  BOOST_C_EXN(b > a);
  BOOST_C_EXN(b >= a);

  BOOST_C_EXN(a == b);
  BOOST_C_EXN(a != b);
}

// comparisons between [1,2] and 0

static void test_12_0() {
  const I a(1,2);
  const int b = 0;

  BOOST_CHECK(!(a < b));
  BOOST_CHECK(!(a <= b));
  BOOST_CHECK(a > b);
  BOOST_CHECK(a >= b);

  BOOST_CHECK(!(a == b));
  BOOST_CHECK(a != b);
}

// comparisons between [1,2] and 1

static void test_12_1() {
  const I a(1,2);
  const int b = 1;

  BOOST_CHECK(!(a < b));
  BOOST_C_EXN(a <= b);
  BOOST_C_EXN(a > b);
  BOOST_CHECK(a >= b);

  BOOST_C_EXN(a == b);
  BOOST_C_EXN(a != b);
}

// comparisons between [1,2] and 2

static void test_12_2() {
  const I a(1,2);
  const int b = 2;

  BOOST_C_EXN(a < b);
  BOOST_CHECK(a <= b);
  BOOST_CHECK(!(a > b));
  BOOST_C_EXN(a >= b);

  BOOST_C_EXN(a == b);
  BOOST_C_EXN(a != b);
}

// comparisons between [1,2] and 3

static void test_12_3() {
  const I a(1,2);
  const int b = 3;

  BOOST_CHECK(a < b);
  BOOST_CHECK(a <= b);
  BOOST_CHECK(!(a > b));
  BOOST_CHECK(!(a >= b));

  BOOST_CHECK(!(a == b));
  BOOST_CHECK(a != b);
}

static void test_12_12() {
  const I a(1,2), b(1,2);
  BOOST_C_EXN(a == b);
  BOOST_C_EXN(a != b);
}

static void test_11_11() {
  const I a(1,1), b(1,1);
  BOOST_CHECK(a == b);
  BOOST_CHECK(!(a != b));
}

static void test_11_1() {
  const I a(1,1);
  const int b = 1;
  BOOST_CHECK(a == b);
  BOOST_CHECK(!(a != b));
}

int test_main(int, char *[]) {
  test_12_34();
  test_13_24();
  test_12_23();
  test_12_E();
  test_12_0();
  test_12_1();
  test_12_2();
  test_12_3();
  test_12_12();
  test_11_11();
  test_11_1();

  return 0;
}