extern "C" {
#include "MyString.h"
}
#include "gtest/gtest.h"
#include <limits.h>


// get: two integer numbers
// return: the maximum between two init numbers

//int getMax(int a, int b) TEST

TEST(getMax,Test_1) {
  int a = 2;
  int b = -1;

  EXPECT_EQ(2, getMax(a, b));
}

TEST(getMax,Test_2) {
  int a = 1;
  int b = 1;

  EXPECT_EQ(1, getMax(a, b));
}

// get: pointer to string (char array)
// return the length of string

// int getStrLen(const char * str); TEST

TEST(getStrLen,Test_1) {
  const char * const str = "abcde";

  EXPECT_EQ(5, getStrLen(str));
}

TEST(getStrLen,Test_2) {
  const char * const str = "abc;def";

  EXPECT_EQ(7, getStrLen(str));
}

TEST(getStrLen,Test_3) {
  const char * const str = "abc\0def";

  EXPECT_EQ(3, getStrLen(str));
}

// check if str2 is extended substring in str1
// with cycle check (cycle on str1), and with step
// return 1 (true) if is substring, 0 (false) if not.

// int checkExtendedSubStrCycle(int start, int step,
//                    const char* str1, const char* str2);

TEST(checkExtendedSubStrCycle,Test_1) {
  const char * const str1 = "abcde";
  const char * const str2 = "abcde";

  EXPECT_EQ(1, checkExtendedSubStrCycle(0, 1, str1, str2));
}

TEST(checkExtendedSubStrCycle,Test_2) {
  const char * const str1 = "abcde";
  const char * const str2 = "abcdea";

  EXPECT_EQ(1, checkExtendedSubStrCycle(0, 1, str1, str2));
}

TEST(checkExtendedSubStrCycle,Test_3) {
  const char * const str1 = "abc";
  const char * const str2 = "abcd";

  EXPECT_EQ(0, checkExtendedSubStrCycle(0, 1, str1, str2));
}


// check if str2 is extended substring in str1
// without cycle check,  with step
// return 1 (true) if is substring, 0 (false) if not.

// int checkExtendedSubStrNonCycle(int start, int step,
//       const char* str1, const char* str2);
//  TEST



TEST(checkExtendedSubStrNonCycle,Test_1) {
  const char * const str1 = "abcde";
  const char * const str2 = "abcde";

  EXPECT_EQ(1, checkExtendedSubStrNonCycle(0, 1, str1, str2));
}

TEST(checkExtendedSubStrNonCycle,Test_2) {
  const char * const str1 = "abcde";
  const char * const str2 = "abcdea";

  EXPECT_NE(1, checkExtendedSubStrNonCycle(0, 1, str1, str2));
}

TEST(checkExtendedSubStrNonCycle,Test_3) {
  const char * const str1 = "abc";
  const char * const str2 = "abcd";

  EXPECT_EQ(0, checkExtendedSubStrNonCycle(0, 1, str1, str2));
}


// compare two words in array
// get: a pointer to the start of str1 and str2
// return 0 if equals, 1 if str1 > str2, -1 if str2 > str1

// int myStrCmp (const char * const s1, const char * const s2);
//  TEST

TEST(myStrCmp,Test_1) {
  const char * const str1 = "abcde";
  const char * const str2 = "abcde";

  EXPECT_EQ(0, myStrCmp(str1, str2));
}

TEST(myStrCmp,Test_2) {
  const char * const str1 = "abcd";
  const char * const str2 = "abcde";

  EXPECT_EQ(-1, myStrCmp(str1, str2));
}

TEST(myStrCmp,Test_3) {
  const char * const str1 = "abcde";
  const char * const str2 = "abcd";

  EXPECT_EQ(1, myStrCmp(str1, str2));
}

// check if char is in delim list
// return 1 (true) is is in, 0 (false) if not

// int isDelim(char c, const char* delim);
//  TEST

TEST(isDelim,Test_1) {
  const char * const delim = ",;*+";
  const char c = ',';

  EXPECT_EQ(1, isDelim(c, delim));
}

TEST(isDelim,Test_2) {
  const char * const delim = "";
  const char c = '+';

  EXPECT_NE(1, isDelim(c, delim));
}

TEST(isDelim,Test_3) {
  const char * const delim = "";
  const char c = '+';

  EXPECT_EQ(0, isDelim(c, delim));
}

// get: array of words
// chenge all delim to DELIM_SIGN

// void changeDelim(char str[], const char* delim);

TEST(changeDelim,Test_1) {
  char str[] = "a;b,c+d";
  const char * const delim = ",;*+";

  changeDelim(str, delim);

  EXPECT_STREQ("a;b;c;d", str);
}

TEST(changeDelim,Test_2) {
  char str[] = "a;b,c+d";
  const char * const delim = "";

  changeDelim(str, delim);

  EXPECT_STREQ("a;b,c+d", str);
}

// get: pointer of current word
// return: pointer of the next word
// char* getNextWord(char const * const str);
//  TEST

TEST(getNextWord,Test_1) {
  char const * const str = "a;bb;ccc";
  char * ans = getNextWord(str);
  EXPECT_STREQ("bb;ccc", ans);
}

// get: pointer of current word
// return: pointer of the end of the word

// char* getEndWord(const char*  const str);
TEST(getEndWord,Test_1) {
  char const * const str = "bc;def";
  char * ans = getEndWord(str);
  EXPECT_EQ('c', *ans);
}

// swap between two chars that point

// void swapChar(char* pChar1, char* pChar2);
// TEST
TEST(swapChar,Test_1) {
  char c1 = 'a';
  char c2 = 'b';
  swapChar(&c1,&c2);
  EXPECT_EQ('b', c1);
}

// get: pointer to a word
// reverce the word

// void reverceWord(char* const str);
// TEST

TEST(reverceWord,Test_1) {
  char str[] = "abcd";
  reverceWord(str);
  EXPECT_STREQ("dcba", str);
}

// swap between two word that point
// retrun: pointer of new junction (to the second word)

// char* replaceLinkedWords(char* const pStr1, char* const pStr2);

TEST(replaceLinkedWords,Test_1) {
  char str[] = "ab;cd";
  char* pCurrent;
  char* pNext;
  pCurrent = str;
  pNext = getNextWord(pCurrent);

  replaceLinkedWords(pCurrent,pNext);
  EXPECT_STREQ("cd;ab", pCurrent);
}

TEST(replaceLinkedWords,Test_2) {
  char str[] = "ab;c";
  char* pCurrent;
  char* pNext;
  pCurrent = str;
  pNext = getNextWord(pCurrent);

  replaceLinkedWords(pCurrent,pNext);
  EXPECT_STREQ("c;ab", pCurrent);
}

TEST(replaceLinkedWords,Test_3) {
  char str[] = "a;bc";
  char* pCurrent;
  char* pNext;
  pCurrent = str;
  pNext = getNextWord(pCurrent);

  replaceLinkedWords(pCurrent,pNext);
  EXPECT_STREQ("bc;a", pCurrent);
}

// get: word array with DELIM_SIGN
// return: number of word in array
// int wordCounter(const char* str);
// TEST

TEST(wordCounter,Test_1) {
  char str[] = "abc;def;ghijklmnop";
  EXPECT_EQ(3, wordCounter(str));
}

TEST(wordCounter,Test_2) {
  char str[] = "a";
  EXPECT_EQ(1, wordCounter(str));
}






// extendedSubStr TEST

TEST(extendedSubStr,Matan_test_3) {
  const char * str1 = "acaaaaaaaabaa";
  const char * str2 = "aaaaab";

  EXPECT_EQ(11, extendedSubStr(1,5,str1,str2));
}


TEST(extendedSubStr,Check_1) {
  const char * str1 = "abc";
  const char * str2 = "abca";

  EXPECT_EQ(0, extendedSubStr(1,1,str1,str2));
}

TEST(extendedSubStr,Check_2) {
  const char * str1 = "t3sae2s1tcba";
  const char * str2 = "test";

  EXPECT_EQ(-1, extendedSubStr(1,1,str1,str2));
}

TEST(extendedSubStr,Check_3) {
  const char * str1 = "t3e2s1tcba";
  const char * str2 = "test";

  EXPECT_EQ(0, extendedSubStr(1,2,str1,str2));
}

TEST(extendedSubStr,Check_4) {
  const char * str1 = "aaaapaaaapaaaac";
  const char * str2 = "cppc";

  EXPECT_EQ(14, extendedSubStr(1,5,str1,str2));
}

TEST(extendedSubStr,Check_5) {
  const char * str1 = "aaaapaaaapaaaaaac";
  const char * str2 = "aacpp";

  EXPECT_EQ(6, extendedSubStr(1,5,str1,str2));
}

TEST(extendedSubStr,Check_6){
  const char * str1 = "aab3c2d1e";
  const char * str2 = "bcd";

  EXPECT_EQ(2, extendedSubStr(0,2,str1,str2));
}

TEST(extendedSubStr,Check_7){
  const char * str1 = "ab3c2d1e";
  const char * str2 = "bcd";

  EXPECT_EQ(1, extendedSubStr(0,2,str1,str2));
}

TEST(extendedSubStr,Check_8){
  const char * str1 = NULL;
  const char * str2 = "bcd";

  EXPECT_EQ(-1, extendedSubStr(0,2,str1,str2));
}

TEST(extendedSubStr,Check_9){
  const char * str1 = "ab3c2d1e";
  const char * str2 = NULL;

  EXPECT_EQ(-1, extendedSubStr(0,2,str1,str2));
}

TEST(extendedSubStr,Check_10){
  const char * str1 = NULL;
  const char * str2 = NULL;

  EXPECT_EQ(-1, extendedSubStr(0,2,str1,str2));
}


//sortDelim TEST

TEST(sortDelim, Check_1){
  char str[] = "a,bc,d";
  const char* delim = ",";
  sortDelim(str,delim);
  ASSERT_STREQ("a;bc;d", str);
}

TEST(sortDelim, Check_2){
  char str[] = "ab,c,def";
  const char* delim = ",";
  sortDelim(str,delim);
  ASSERT_STREQ("ab;c;def", str);
}

TEST(sortDelim, Check_3){
  char str[] = "c,ab,def";
  const char* delim = ",";
  sortDelim(str,delim);
  ASSERT_STREQ("ab;c;def", str);
}

TEST(sortDelim, Check_4){
  char str[] = "def,ab,c";
  const char* delim = ",";
  sortDelim(str,delim);
  ASSERT_STREQ("ab;c;def", str);
}

TEST(sortDelim,Check_5){
   char str[] = "banana,ana,a,na,anana";
   const char* delim=",";
   sortDelim(str,delim);
   ASSERT_STREQ("a;ana;anana;banana;na",str);
}

TEST(sortDelim, Check_6){
  char str[] = "a,bc+def.ghij";
  const char* delim="+,.-";
  sortDelim(str,delim);
  ASSERT_STREQ("a;bc;def;ghij",str);
}

TEST(sortDelim, Check_7){
  char str[] = "a";
  const char* delim="+,.-";
  sortDelim(str,delim);
  ASSERT_STREQ("a",str);
}

TEST(sortDelim, Check_8){
  char str[] = "";
  const char* delim="+,.-";
  sortDelim(str,delim);
  ASSERT_STREQ("",str);
}
