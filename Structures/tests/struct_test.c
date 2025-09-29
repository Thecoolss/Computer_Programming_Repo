#include "rectangle.h"
#include "utest.h"
#include <stdio.h>

UTEST(RectangleTests, area) {
  Rectangle r = {10, 5};
  ASSERT_EQ(50, area(r));
}

UTEST(RectangleTests, area_zero) {
  Rectangle r_zero_w = {0, 5};
  ASSERT_EQ(0, area(r_zero_w));

  Rectangle r_zero_h = {10, 0};
  ASSERT_EQ(0, area(r_zero_h));
}

UTEST(RectangleTests, area_negative_dimension) {
  Rectangle r_neg_w = {-5, 10};
  ASSERT_EQ(-1, area(r_neg_w));

  Rectangle r_neg_h = {10, -5};
  ASSERT_EQ(-1, area(r_neg_h));
}

UTEST(RectangleTests, grow_basic) {
  Rectangle r = {10, 5};
  grow(&r, 3, 7);
  ASSERT_EQ(13, r.w);
  ASSERT_EQ(12, r.h);
  ASSERT_EQ(156, area(r));
}

UTEST(RectangleTests, grow_negative_delta_valid_result) {
  Rectangle r = {10, 5};
  grow(&r, -3, -1);
  ASSERT_EQ(7, r.w);
  ASSERT_EQ(4, r.h);
  ASSERT_EQ(28, area(r));
}

UTEST(RectangleTests, grow_negative_delta_zero_result) {
  Rectangle r = {10, 5};
  grow(&r, -20, -10);
  ASSERT_EQ(10,r.w);
  ASSERT_EQ(5,r.h);
}

UTEST(RectangleTests, grow_null_pointer) { grow(NULL, 10, 10); }

UTEST_MAIN();