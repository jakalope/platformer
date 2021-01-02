#include "platformer/point.h"

#include <gtest/gtest.h>
#include <sstream>

namespace platformer {

using ScalarTypes = ::testing::Types<int32_t, float>;

template <typename T>
using PointOperator = ::testing::Test;
TYPED_TEST_SUITE(PointOperator, ScalarTypes);

TYPED_TEST(PointOperator, Equality) {
  using Point2T = Point2<TypeParam>;
  {
    Point2T a(1, 2);
    Point2T b(-3, 5);
    ASSERT_EQ(a, a);
    ASSERT_NE(a, b);
    ASSERT_NE(b, a);
  }
  {
    Point2T a(1, 2);
    Point2T b(1, 5);
    ASSERT_EQ(a, a);
    ASSERT_NE(a, b);
    ASSERT_NE(b, a);
  }
  {
    Point2T a(2, 1);
    Point2T b(5, 1);
    ASSERT_EQ(a, a);
    ASSERT_NE(a, b);
    ASSERT_NE(b, a);
  }
}

TYPED_TEST(PointOperator, Inequality) {
  using Point2T = Point2<TypeParam>;
  {
    Point2T a(0, 1);
    Point2T b(1, 0);
    ASSERT_LT(a, b);
    ASSERT_GT(b, a);
    ASSERT_LE(a, b);
    ASSERT_GE(b, a);
  }
  {
    Point2T a(0, 0);
    Point2T b(1, 1);
    ASSERT_LT(a, b);
    ASSERT_GT(b, a);
    ASSERT_LE(a, b);
    ASSERT_GE(b, a);
  }
  {
    Point2T a(-1, 2);
    Point2T b(0, 0);
    ASSERT_LT(a, b);
    ASSERT_GT(b, a);
    ASSERT_LE(a, b);
    ASSERT_GE(b, a);
  }
}

TYPED_TEST(PointOperator, Negation) {
  using Point2T = Point2<TypeParam>;
  ASSERT_EQ(Point2T(1, 2), -Point2T(-1, -2));
  ASSERT_EQ(Point2T(-1, 2), -Point2T(1, -2));
  ASSERT_EQ(Point2T(-1, -2), -Point2T(1, 2));
}

TYPED_TEST(PointOperator, TwoPoints) {
  using Point2T = Point2<TypeParam>;
  Point2T left(1, 2);
  Point2T right(-3, 5);
  ASSERT_EQ(Point2T(-2, 7), left + right);
  ASSERT_EQ(Point2T(-2, 7), right + left);
  ASSERT_EQ(Point2T(4, -3), left - right);
}

TYPED_TEST(PointOperator, PointAndScalar) {
  using Point2T = Point2<TypeParam>;
  Point2T pt(1, 2);
  int32_t scalar{3};
  ASSERT_EQ(Point2T(4, 5), pt + scalar);
  ASSERT_EQ(Point2T(4, 5), scalar + pt);
  ASSERT_EQ(Point2T(-2, -1), pt - scalar);
  ASSERT_EQ(Point2T(3, 6), pt * scalar);
  ASSERT_EQ(Point2T(3, 6), scalar * pt);
}

TYPED_TEST(PointOperator, PointPrinter) {
  using Point2T = Point2<TypeParam>;
  std::ostringstream ss;
  ss << Point2T(1, 2);
  auto str = ss.str();
  ASSERT_EQ(str, "(1,2)");
}

} // namespace platformer
