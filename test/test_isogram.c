#include "vendor/unity.h"
#include "../src/isogram.h"
#include <stdlib.h>

//Äquivalenzklassen
/*
    -empty string
    -short strings
    -long strings
    -upper case / lower case
    -strings with special characters !?%
    strings with numbers (digits 0-9)

*/


//this is a unit test
void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}

void test_short_strings() {
    //positive Tests
    TEST_ASSERT_TRUE(is_isogram("a"));
    TEST_ASSERT_TRUE(is_isogram("b"));
    TEST_ASSERT_TRUE(is_isogram("c"));

    TEST_ASSERT_TRUE(is_isogram("abc"));
    TEST_ASSERT_TRUE(is_isogram("xyz"));
    TEST_ASSERT_TRUE(is_isogram("def"));

    //negative Tests
    TEST_ASSERT_FALSE(is_isogram("aa"));
    TEST_ASSERT_FALSE(is_isogram("bb"));
    TEST_ASSERT_FALSE(is_isogram("cc"));
}

void test_long_strings() {
    //positive Tests
    TEST_ASSERT_TRUE(is_isogram("Dialogschwerpunkt"));

    //negative Tests
    TEST_ASSERT_FALSE(is_isogram("Dialogschwerpunkte"));
}

void test_upper_case_strings() {
    //positive Tests
    TEST_ASSERT_TRUE(is_isogram("DIALOGSCHWERPUNKT"));
    TEST_ASSERT_TRUE(is_isogram("ABC"));

    //negative Tests
    TEST_ASSERT_FALSE(is_isogram("DIALOGSCHWERPUNKTE"));
    TEST_ASSERT_FALSE(is_isogram("BEE"));
}

void test_lower_case_strings() {
    //positive Tests
    TEST_ASSERT_TRUE(is_isogram("dialogschwerpunkt"));

    //negative Tests
    TEST_ASSERT_FALSE(is_isogram("dialogschwerpunkte"));
}

void test_mixed_case_strings() {
    //positive Tests
    TEST_ASSERT_TRUE(is_isogram("DIaLOGScHWERpUNkT"));
    TEST_ASSERT_TRUE(is_isogram("AbC"));

    //negative Tests
    TEST_ASSERT_FALSE(is_isogram("DIaLOGScHWeRpUNKTE"));
    TEST_ASSERT_FALSE(is_isogram("BEe"));
}

void test_special_characters_strings() {
    //positive Tests
    TEST_ASSERT_TRUE(is_isogram("ab!!c!?%"));

    //negative Tests
    TEST_ASSERT_FALSE(is_isogram("!abbc??$"));
}

void test_digit_strings() {
    //positive Tests
    TEST_ASSERT_TRUE(is_isogram("0123456789"));

    //negative Tests
    TEST_ASSERT_FALSE(is_isogram("123451"));
}

// special characters are ignored
//any number of occurences is fine e.g. aabbcc


int main(void)
{
   UnityBegin("isIsogram");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_short_strings);
   RUN_TEST(test_long_strings);
   RUN_TEST(test_upper_case_strings);
   RUN_TEST(test_lower_case_strings);
   RUN_TEST(test_mixed_case_strings);
   RUN_TEST(test_special_characters_strings);
   RUN_TEST(test_digit_strings);

   UnityEnd();
   return 0;
}
