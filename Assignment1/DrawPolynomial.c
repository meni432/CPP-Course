#include <stdio.h>
#define POW_2(X) ((X)*(X))
#define POW_3(X) ((X)*(X)*(X))
#define X_RANGE 35
#define Y_RANGE 10
#define EPSILON 0.5

// return Absolute value of x
double get_abs(double x)
{
  if (x < 0)
    return (-1)*x;
  return x;
}

// return the value of the polynomial y(x)=a+b*x+c*x^2+d*x^3
double get_polynomial_value(int x, double a, double b, double c, double d)
{
  return a + b*x + c*(POW_2(x)) + d*(POW_3(x));
}

char get_grid_value(int x, int y, double y_value)
{
  // If for the current value of x the polynomial value the y
  // value is close (< ±1⁄2) Return character '*'
  if (get_abs(y_value - y) < EPSILON)
    return '*';

  // check if the value on the axes
  // check if on (0,0)
  if (x == 0 && y == 0)
    return '+';
  // check if on (0,y)
  if (x == 0)
    return '|';
  // check if on (x, 0)
  if (y == 0)
    return '-';

  // If for the current value of x the polynomial value the y value is
  // not close (>= ±1⁄2) then a  blank character is return.
  // (if the (X,Y) pair is not on the axes
  return ' ';
}

void print_polynomial(double a, double b, double c, double d)
{
  int i, j;
  double y_value;

  for (i = Y_RANGE; i >= -Y_RANGE; i--)
  {
    for (j = -X_RANGE; j <= X_RANGE; j++)
    {
      y_value = get_polynomial_value(j,a,b,c,d);
      printf("%c", get_grid_value(j,i, y_value));
    }
    printf("\n");
  }
}

int main()
{
  double select_a, select_b, select_c, select_d;

  printf("y(x)=a+b*x+c*x^2+d*x^3\n");

  printf("Select a:\n");
  scanf("%lf", &select_a);

  printf("Select b:\n");
  scanf("%lf", &select_b);

  printf("Select c:\n");
  scanf("%lf", &select_c);

  printf("Select d:\n");
  scanf("%lf", &select_d);

  printf("y(x)=(%.3f)+(%.3f)*x+(%.3f)*x^2+(%.3f)*x^3\n",
        select_a, select_b, select_c, select_d);

  // print the polynomial
  print_polynomial(select_a, select_b, select_c, select_d);
  return 0;
}
