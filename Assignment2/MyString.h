#pragma once

//Checks if str2 is a sub string of str1.
//return :  the location of first time str2 is a sub string of str1.
int extendedSubStr(int isCyclic, int step, const char* str1,
                                                const char* str2);

//Sorts the words in str separated by the chars in delim.
void sortDelim(char str[], const char* delim);


// get: two integer numbers
// return: the maximum between two init numbers
int getMax(int a, int b);
// get: pointer to string (char array)
// return the length of string
int getStrLen(const char * str);
// check if str2 is extended substring in str1
// with cycle check (cycle on str1), and with step
// return 1 (true) if is substring, 0 (false) if not.
int checkExtendedSubStrCycle(int start, int step,
                    const char* str1, const char* str2);
// check if str2 is extended substring in str1
// without cycle check,  with step
// return 1 (true) if is substring, 0 (false) if not.
int checkExtendedSubStrNonCycle(int start, int step,
      const char* str1, const char* str2);
// the assignment function extendedSubStr
int extendedSubStr(int isCyclic, int step, const char* str1,
                                              const char* str2);
// compare two words in array
// get: a pointer to the start of str1 and str2
// return 0 if equals, 1 if str1 > str2, -1 if str2 > str1
int myStrCmp (const char * const s1, const char * const s2);
// check if char is in delim list
// return 1 (true) is is in, 0 (false) if not
int isDelim(char c, const char* delim);
// get: array of words
// chenge all delim to DELIM_SIGN
void changeDelim(char str[], const char* delim);
// get: pointer of current word
// return: pointer of the next word
char* getNextWord(char const * const str);
// get: pointer of current word
// return: pointer of the end of the word
char* getEndWord(const char*  const str);
// swap between two chars that point
void swapChar(char* pChar1, char* pChar2);
// get: pointer to a word
// reverce the word
void reverceWord(char* const str);
// swap between two word that point
// retrun: pointer of new junction (to the second word)
char* replaceLinkedWords(char* const pStr1, char* const pStr2);
// get: word array with DELIM_SIGN
// return: number of word in array
int wordCounter(const char* str);
// the assignment function sortDelim
void sortDelim(char str[], const char* delim);
