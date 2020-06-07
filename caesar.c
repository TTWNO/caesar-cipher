#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FIRST_CHAR 65
#define LAST_CHAR 90
#define MODULO_POINT 91

static char* allowed = "ABCDEFGHIJKLMNOPQRSTUBWXYZ";

char shift_by(int by, char c)
{
  /* if C is in the 'allowed' list */
  if (strchr(allowed, c))
  {
    /* if c + shift is more than 'Z' */
    if (c + by > LAST_CHAR)
      /* return 'A' + remainder of shift minus 'Z' + 1;
       * in essense, start at A and add what was left from the shift after reaching Z */
      return FIRST_CHAR + ((c + by) % MODULO_POINT);
    /* otherwise; if c + shift is not more than 'Z' */ 
    else
      /* return char + offset */
      return c + by;
  }
  /* if not an allowed character */
  else
  {
    return c;
  }
}

char* shift_str_by(int by, char* c, int len)
{
  char* done = malloc(sizeof(char) * len);
  int i;
  for (i = 0; i < len; ++i)
  {
    done[i] = shift_by(by, toupper(c[i]));
  }
  return done;
}

int main()
{
  static char message[250] = "Hello, Caesar!";

  printf("A + 2 = %c\n", shift_by(2, 'A'));
  printf("Z + 1 = %c\n", shift_by(1, 'Z'));
  int len = strlen(message) + 1;
  char* done = shift_str_by(3, message, len);
  printf("'Hello, Caesar!' + 3 = %s\n", done);

  return 0;
}
