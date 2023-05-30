#include <stdint.h>
#include <unity.h>
#include <bit-manipulations.c>

void testSetBit() {
  // Set Up
  uint32_t data = 0x00000000;
  uint32_t expected = data;
  Err error = 0;
  int i = 0;

  // Test Working Case
  for(i; i < 32; i++) {
    error = setBit(&data, i);
    expected = (expected << 1) + 1;
    TEST_ASSERT_TRUE_MESSAGE(data == expected,"Data bits not set as expected");
    TEST_ASSERT_TRUE_MESSAGE(error == 0,"Make sure to implement setBit, you silly goose!");
  }

  // Test Error Case
  error = clearBit(&data, 32);
  TEST_ASSERT_TRUE_MESSAGE(data == expected,"Should not change data; n exceeds bounds");
  TEST_ASSERT_TRUE_MESSAGE(error != 0,"Make sure to error check, you silly goose!");
}

void testInvertBit() {
  // Set Up
  uint32_t data = 0x02468ACE;
  uint32_t expected = 0xFDB97531;
  Err error = 0;
  int i = 0;

  // Test Working Case
  for(i; i < 32; i++) {
    error = invertBit(&data, i);
  TEST_ASSERT_TRUE_MESSAGE(error == 0,"Make sure to implement setBit, you silly goose!");
  }
  TEST_ASSERT_TRUE_MESSAGE(data == expected,"Data bits not set as expected");

  // Test Error Case
  error = clearBit(&data, 32);
  TEST_ASSERT_TRUE_MESSAGE(data == expected,"Should not change data; n exceeds bounds");
  TEST_ASSERT_TRUE_MESSAGE(error != 0,"Make sure to error check, you silly goose!");
}

void testClearBit() {
  // Set Up
  uint32_t data = 0xFFFFFFFF;
  uint32_t expected;
  Err error = 0;
  int i = 31;

  // Test Working Case
  error = clearBit(&data, i);
  expected = 0x7FFFFFFF;
  i--;
  TEST_ASSERT_TRUE_MESSAGE(data == expected,"DAta bits not cleared as expected");
  TEST_ASSERT_TRUE_MESSAGE(error == 0,"Make sure to implement clearBit, you silly goose!");
  for(i; i > -1; i--) {
    error = clearBit(&data, i);
    expected = expected >> 1;
    TEST_ASSERT_TRUE_MESSAGE(data == expected,"Data bits not cleared as expected");
    TEST_ASSERT_TRUE_MESSAGE(error == 0,"Make sure to implement clearBit, you silly goose!");
  }

  // Test Error Case
  error = clearBit(&data, 32);
  TEST_ASSERT_TRUE_MESSAGE(data == expected,"Should not change data; n exceeds bounds");
  TEST_ASSERT_TRUE_MESSAGE(error != 0,"Make sure to error check, you silly goose!");
}

void testMaskBit() {
  // Set Up
  uint32_t data = 0xAAAAAAAA;
  uint8_t maskedBit = 0;
  Err error = 0;

  // Test Working State
  for (int i = 0; i < 32; i++) {
    error = maskBit(&maskedBit, data, i);
    TEST_ASSERT_TRUE_MESSAGE(maskedBit == (i%2),"Bits not masked as expected");
    TEST_ASSERT_TRUE_MESSAGE(error == 0,"Make sure to implement maskBit, you silly goose!");
  }

  // Test Error Case
  uint8_t tmpBit = maskedBit;
  error = maskBit(&maskedBit, data, 32);
  TEST_ASSERT_TRUE_MESSAGE(maskedBit == tmpBit,"");
  TEST_ASSERT_TRUE_MESSAGE(error == 1,"Make sure to error check, you silly goose!");
}

void testAdd() {
  return;
}

void testMac() {
  return;
}

void testBitShftLft() {
  return;
}

void testBitShftRt() {
  return;
}
