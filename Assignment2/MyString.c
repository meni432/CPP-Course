#include "MyString.h"
#include <stdio.h>
#define DELIM_SIGN ';'

// get: two integer numbers
// return: the maximum between two init numbers
int getMax(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

// get: pointer to string (char array)
// return the length of string
int getStrLen(const char * str)
{
  int length = 0;
  while (*str) {
    str++;
    length++;
  }
  return length;
}

// check if str2 is extended substring in str1
// with cycle check (cycle on str1), and with step
// return 1 (true) if is substring, 0 (false) if not.
int checkExtendedSubStrCycle(int start, int step,
                          const char* str1, const char* str2)
{
  int i;
  int nStr1Length, nStr2Length;
  int numberOfLoop;
  nStr1Length = getStrLen(str1);
  nStr2Length = getStrLen(str2);
  numberOfLoop = getMax(nStr1Length, nStr2Length) + start;

  for (i = start; i < numberOfLoop*step && *str2; i += step)
  {
    if (str1[i%nStr1Length] == *str2)
      str2++;
    else
    {

      return 0;
    }

  }
  if (!*str2)
    return 1;

  return 0;
}

// check if str2 is extended substring in str1
// without cycle check,  with step
// return 1 (true) if is substring, 0 (false) if not.
int checkExtendedSubStrNonCycle(int start, int step,
      const char* str1, const char* str2)
{
  int nStr1Pos = start;
  int nStr1Len = getStrLen(str1);

  while (nStr1Pos < nStr1Len && *str2 != '\0')
  {
    if (str1[nStr1Pos] == *str2)
      str2++;
    else
      return 0;


    nStr1Pos += step;

  }
  if (!*str2)
    return 1;

  return 0;
}

// the assignment function extendedSubStr
int extendedSubStr(int isCyclic, int step, const char* str1,
                                                const char* str2)
{
  int i, ans;
  int nStr1Length;

  if (str1 == NULL || str2 == NULL || step <= 0)
  {
    return -1;
  }

  nStr1Length = getStrLen(str1);

  for (i = 0; i < nStr1Length; i++)
  {
    if (str1[i] == str2[0])
    {
      if (isCyclic)
      {
        ans = checkExtendedSubStrCycle(i, step, str1, str2);
        if (ans)
          return i;
      }
      else
      {
        ans = checkExtendedSubStrNonCycle(i, step, str1, str2);
        if (ans)
          return i;
      }
    }
  }
  return -1;
}

// compare two words in array
// get: a pointer to the start of str1 and str2
// return 0 if equals, 1 if str1 > str2, -1 if str2 > str1
int myStrCmp (const char * const str1, const char * const str2)
{
    const unsigned char *pStr1 = (const unsigned char *)str1;
    const unsigned char *pStr2 = (const unsigned char *)str2;

    while (*pStr1 != '\0' && *pStr1 != DELIM_SIGN) {
        if (*pStr2 == '\0' || *pStr2 == DELIM_SIGN) return  1;
        if (*pStr2 > *pStr1)   return -1;
        if (*pStr1 > *pStr2)   return  1;

        pStr1++;
        pStr2++;
    }

    if (*pStr2 != '\0' && *pStr2 != DELIM_SIGN) return -1;

    return 0;
}

// check if char is in delim list
// return 1 (true) is is in, 0 (false) if not
int isDelim(const char c, const char* delim)
{
  while (*delim)
  {
    if (*delim == c)
    {
      return 1;
    }
    delim++;
  }
  return 0;
}

// get: array of words
// chenge all delim to DELIM_SIGN
void changeDelim(char str[], const char* delim)
{
  while (*str)
  {
    if (isDelim(*str, delim))
    {
      *str = DELIM_SIGN;
    }
    str++;
  }
}

// get: pointer of current word
// return: pointer of the next word
char* getNextWord(char const * const str)
{
  char* pAns = (char*)str;

  while (*pAns != DELIM_SIGN && *pAns)
  {
    pAns++;
  }

  return (pAns+1);
}

// get: pointer of current word
// return: pointer of the end of the word
char* getEndWord(const char*  const str)
{
  char* pAns = (char*)str;
  while (*pAns != DELIM_SIGN && *pAns)
  {
    pAns++;
  }

  return (pAns-1);
}

// swap between two chars that point
void swapChar(char* pChar1, char* pChar2)
{
  char temp = *pChar1;
  *pChar1 = *pChar2;
  *pChar2 = temp;
}

// get: pointer to a word
// reverce the word
void reverceWord(char* const str)
{
  char* start = str;
  char* end = getEndWord(str);
  while (start < end)
  {
    swapChar(start, end);
    start++;
    end--;
  }
}

// swap between two word that point
// retrun: pointer of new junction (to the second word)
char* replaceLinkedWords(char* const pStr1, char* const pStr2)
{
  char* start;
  char* end;
  char* pNewDelim;
  start = pStr1;
  end = getEndWord(pStr2);
  reverceWord(pStr1);
  reverceWord(pStr2);

  while (start <= end)
  {
    swapChar(start, end);
    if (*start == DELIM_SIGN)
    {
      pNewDelim = start+1;
    }
    start++;
    end--;
  }

  return pNewDelim;
}

// get: word array with DELIM_SIGN
// return: number of word in array
int wordCounter(const char* str)
{
  int nAns = 1;
  while (*str)
  {
    if (*str == DELIM_SIGN)
      nAns++;

    str++;
  }

  return nAns;
}

// the assignment function sortDelim
void sortDelim(char str[], const char* delim)
{
  char* pCurrent;
  char* pNext;
  int i, numberOfWords;
  changeDelim(str,delim);

  numberOfWords = wordCounter(str);
  for (i = 0; i < numberOfWords; i++)
  {
    pCurrent = str;
    pNext = getNextWord(pCurrent);
    while (*pNext && *(pNext-1))
    {
      if (myStrCmp(pCurrent, pNext) == 1)
      {
        pCurrent = replaceLinkedWords(pCurrent, pNext);
      }
      else
      {
        pCurrent = pNext;
      }

      pNext = getNextWord(pCurrent);
    }

  }

}
