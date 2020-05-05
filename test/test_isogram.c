#include "vendor/unity.h"
#include "../src/isogram.h"
#include <stdlib.h>

void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}

int main(void)
{
   UnityBegin("isIsogram");

   RUN_TEST(test_empty_string);

   UnityEnd();
   return 0;
}
