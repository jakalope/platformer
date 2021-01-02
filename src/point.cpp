#include "platformer/point.h"

std::ostream& operator<<(std::ostream& out, const platformer::Point2i& pt) {
  out << '(' << pt.x() << ',' << pt.y() << ')';
  return out;
}

std::ostream& operator<<(std::ostream& out, const platformer::Point2f& pt) {
  out << '(' << pt.x() << ',' << pt.y() << ')';
  return out;
}
