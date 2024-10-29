#include <stdio.h>
#include <math.h>

int main() {
  float a = 10.52 * pow(10, -12) * 8.36 + pow(10, -7);
  float b = 45.98 * pow(2, -10);
  float c = 17.61 * pow(10, -11) + 45.23 * pow(10, -13);
  float d = 10 * pow(2, -10);
  float e = 32.6 * pow(10, -8) + 18.56 * pow(2, -5);

  float result = (a * b) / (c * d * e);

  printf("The result for above expression is %f\n", result);

  return 0;
}