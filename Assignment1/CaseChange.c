#define  POW(A) ((A)*(A))
#define GET_UPPER(C) ((C - 'a' + 'A'))
#define GET_LOWER(C) ((C - 'A' + 'a'))
#define GET_NUM_CHAR_VALUE(C) ((C - '0'))
#include <stdio.h>

void print_case_change(char input)
{
  int num;

  // If the character entered is a lower case English letter
  // print character in upper case
  if (input >= 'a' && input <= 'z')
    printf("%c->%c\n", input, GET_UPPER(input));
  // If the character entered is an upper case English letter
  // print charcter in lower case
  else if (input >= 'A' && input <= 'Z')
    printf("%c->%c\n", input, GET_LOWER(input));
  // If the character entered is a digit (0‐9)
  // print the square of the input digit
  else if (input >= '0' && input <= '9')
  {
    num = GET_NUM_CHAR_VALUE(input);
    printf("%d\n", POW(num));
  }
  // If that the input is not in one of these
  //  sets of characters (0‐9, A‐Z, a‐z)
  // print "Invalid Input"
  else
    printf("%c->Invalid Input\n",input);
}

int main()
{
  char input;
  scanf("%c", &input);
  print_case_change(input);

  return 0;
}
