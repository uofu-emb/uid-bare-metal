#include <lab-tests/00.hello-tests.c>
#include <lab-tests/01.gpio-tests.c>

int main()
{
  UNITY_BEGIN();

  // implement the functions called by these unit tests
  RUN_TEST(testSetBit);
  RUN_TEST(testClearBit);
  RUN_TEST(testMaskBit);

  // implement these unit tests
  RUN_TEST(testAdd);
  RUN_TEST(testMac);
  RUN_TEST(testBitShftLft);
  RUN_TEST(testBitShftRt);

  RUN_TEST(startGPIO_test);

  RUN_TEST(setGPIO_test);
  RUN_TEST(clearGPIO_test);
  RUN_TEST(invertGPIO_test);

  UNITY_END();
}