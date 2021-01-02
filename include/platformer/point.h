#pragma once

#include <cstdint>
#include <iostream>
#include <tuple>

namespace platformer {

template <typename T>
class Point2 final {
public:
  constexpr Point2(T x, T y) : x_(x), y_(y) {}

  constexpr T x() const noexcept {
    return x_;
  }

  constexpr T y() const noexcept {
    return y_;
  }

private:
  T x_;
  T y_;
};

template <typename T>
constexpr bool operator==(Point2<T> left, Point2<T> right) {
  return std::make_tuple(left.x(), left.y()) ==
      std::make_tuple(right.x(), right.y());
}

template <typename T>
constexpr bool operator!=(Point2<T> left, Point2<T> right) {
  return !(left == right);
}

template <typename T>
constexpr bool operator<(Point2<T> left, Point2<T> right) {
  return std::make_tuple(left.x(), left.y()) <
      std::make_tuple(right.x(), right.y());
}

template <typename T>
constexpr bool operator>(Point2<T> left, Point2<T> right) {
  return std::make_tuple(left.x(), left.y()) >
      std::make_tuple(right.x(), right.y());
}

template <typename T>
constexpr bool operator<=(Point2<T> left, Point2<T> right) {
  return std::make_tuple(left.x(), left.y()) <=
      std::make_tuple(right.x(), right.y());
}

template <typename T>
constexpr bool operator>=(Point2<T> left, Point2<T> right) {
  return std::make_tuple(left.x(), left.y()) >=
      std::make_tuple(right.x(), right.y());
}

template <typename T>
constexpr Point2<T> operator-(Point2<T> pt) {
  return Point2<T>(-pt.x(), -pt.y());
}

template <typename T>
constexpr Point2<T> operator+(Point2<T> left, Point2<T> right) {
  return Point2<T>(left.x() + right.x(), left.y() + right.y());
}

template <typename T>
constexpr Point2<T> operator-(Point2<T> left, Point2<T> right) {
  return left + (-right);
}

template <typename T, typename Scalar>
constexpr Point2<T> operator+(Point2<T> left, Scalar right) {
  return Point2<T>(left.x() + right, left.y() + right);
}

template <typename T, typename Scalar>
constexpr Point2<T> operator+(Scalar left, Point2<T> right) {
  return right + left;
}

template <typename T, typename Scalar>
constexpr Point2<T> operator-(Point2<T> left, Scalar right) {
  return Point2<T>(left.x() - right, left.y() - right);
}

template <typename T, typename Scalar>
constexpr Point2<T> operator*(Point2<T> left, Scalar right) {
  return Point2<T>(left.x() * right, left.y() * right);
}

template <typename T, typename Scalar>
constexpr Point2<T> operator*(Scalar left, Point2<T> right) {
  return Point2<T>(left * right.x(), left * right.y());
}

using Point2i = Point2<int32_t>;
using Point2f = Point2<float>;

} // namespace platformer

std::ostream& operator<<(std::ostream& out, const platformer::Point2i& pt) {
  out << '(' << pt.x() << ',' << pt.y() << ')';
  return out;
}

std::ostream& operator<<(std::ostream& out, const platformer::Point2f& pt) {
  out << '(' << pt.x() << ',' << pt.y() << ')';
  return out;
}
