#include "vendor/unity.h"
#include "../src/isogram.h"
#include <stdlib.h>

void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}

void test_single_characters(void)
{
   TEST_ASSERT_TRUE(is_isogram("a"));
   TEST_ASSERT_TRUE(is_isogram("B"));
   TEST_ASSERT_TRUE(is_isogram("z"));
}

void test_multiple_multiple_same_characters(void)
{
   TEST_ASSERT_FALSE(is_isogram("aa"));
   TEST_ASSERT_FALSE(is_isogram("BB"));
   TEST_ASSERT_FALSE(is_isogram("zz"));
}

void test_isograms_lowercase(void)
{
  TEST_ASSERT_TRUE(is_isogram("asdfjkl"));
  TEST_ASSERT_TRUE(is_isogram("sa"));
  TEST_ASSERT_TRUE(is_isogram("isogram"));
}

void test_isograms_different_casings(void)
{
  TEST_ASSERT_FALSE(is_isogram("aA"));
}

void test_isograms_ignore_specialchars(void)
{
  TEST_ASSERT_TRUE(is_isogram("isogram!!"));
  TEST_ASSERT_TRUE(is_isogram("isogram&&"));
  TEST_ASSERT_TRUE(is_isogram("isogram???"));
  TEST_ASSERT_TRUE(is_isogram("isogram   "));
}

int main(void)
{
   UnityBegin("test/test_isogram.c");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_single_characters);
   RUN_TEST(test_multiple_multiple_same_characters);
   RUN_TEST(test_isograms_lowercase);
   RUN_TEST(test_isograms_different_casings);
   RUN_TEST(test_isograms_ignore_specialchars);

   UnityEnd();

   return 0;
}
