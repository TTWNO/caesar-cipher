#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char shift_by(char old_char, int by)
{
  /* if signed (default) char, then it can overflow 
   * 'z' (122) + 12 = -121 if signed
   * 'z' (122) + 12 = 134 if unsigned */
  unsigned char shifted_char;
  /* return the character as is if the character is not an alphabetic character */
  if (!isalpha(old_char))
    return old_char;

  shifted_char = old_char + by;
  /* if the old_char is a lower case letter and the shifted character has gone past the value of a lowercase 'z' */
  if (islower(old_char) && shifted_char > 'z')
  {
    /* wrap around back to 'a' */
    shifted_char = 'a' + (shifted_char % 'z' - 1);
  }
  /* same as above with uppercase */
  if (isupper(old_char) && shifted_char > 'Z')
  {
    /* same as above with uppercase */
    shifted_char = 'A' + (shifted_char % 'Z' - 1);
  }

  /* check for negative letters */
  if (islower(old_char) && shifted_char < 'a')
  {
    /* wrap around to the end of the lower alphabet */
    shifted_char = 'z' - ('a' - shifted_char - 1);
  }
  if (isupper(old_char) && shifted_char < 'A')
  {
    shifted_char = 'Z' - ('A' - shifted_char - 1);
  }

  return shifted_char;
}

bool all_digits(char* string)
{
  int len = strlen(string);
  for (int i = 0; i < len; ++i)
  {
    /* if any character in the string is not a digit */
    if (!isdigit(string[i]))
    {
      return false;
    }
  }
  return true;
}

void shift_str_by(char* c, int by, char* shifted)
{
  int len = strlen(c);
  for (int i = 0; i < len; ++i)
  {
    shifted[i] = shift_by(c[i], by);
  }
}

