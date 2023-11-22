#include "math.h"

int divRoundClosest(const int n, const int d)
{
  return ((n < 0) == (d < 0)) ? ((n + d/2)/d) : ((n - d/2)/d);
}

