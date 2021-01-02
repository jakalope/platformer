#pragma once

#include "platformer/point.h"

// Graphics abstraction layer. This allows us to switch between any
// appropriately featured graphics library without re-implementing algorithm
// details.

namespace platformer {
namespace graphics {

// A thing that can be drawn using a graphics library.
class Drawable {
public:
  virtual void draw() const = 0;
  virtual ~Drawable() = default;
};

class Rectangle2f final : public Drawable {
public:
  Rectangle2f(Point2f upper_left, Point2f lower_right);
  void draw() const;

private:
  Point2f upper_left_;
  Point2f lower_right_;
};

} // namespace graphics
} // namespace platformer
