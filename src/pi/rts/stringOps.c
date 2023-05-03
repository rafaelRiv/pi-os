#include "stringOps.h"

void toString(char str[], int num)
{
    int i, rem, len = 0, n;
 
    n = num;

    if(n == 0) {
      str[0] = '0';
      len++;
    } else {
      while (n != 0)
      {
          len++;
          n /= 10;
      }
      for (i = 0; i < len; i++)
      {
          rem = num % 10;
          num = num / 10;
          str[len - (i + 1)] = rem + '0';
      }
    }
    str[len] = '\0';
}

char head(char *str) {
  return str[0];
}
 
