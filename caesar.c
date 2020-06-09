#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* maximum size of input string */
size_t BUFF_SIZE = 4096;

char shift_by(char, int);
void shift_str_by(char*, int, char*);
bool all_digits(char*);
void usage();

int main(int argc, char* argv[])
{
  /* if the first paramater is not provided;
   * or the value supplied as the first paramater is less than one;
   * or the first paramater contains anything other than numbers, like a period */
  if (argc != 2 || atoi(argv[1]) < 1 || !all_digits(argv[1]))
  {
    /* print program usage info */
    usage();
    /* tell computer this program terminated unsucessfully */
    return -1;
  }

  /* the first argument/paramater becomes the int shift */
  int shift = atoi(argv[1]);
  /* max line size of 4095 chars */
  char* line = malloc(sizeof(char) * BUFF_SIZE);
  char* crypt_line = malloc(sizeof(char) * BUFF_SIZE);
  /* get line from standard input until end of file, or Ctrl+D */
  while (getline(&line, &BUFF_SIZE, stdin) != EOF)
  {
    /* put the result of *line* shifted by *shift* into *crypt_line* */
    shift_str_by(line, shift, crypt_line);
    /* print crypt_line string */  
    printf("%s", crypt_line);
    /* clear crypt_line string of previous results */
    memset(crypt_line, 0, BUFF_SIZE);
  }

  /* free the memory used by the line and crypt_line strings */
  free(line);
  free(crypt_line);
  return 0;
}

void usage()
{
  /* angle brackets indicate a required paramater */
  printf("Usage: caesar <key>\n");
  /* P.S. for reference purposes square brackets indicate an optional one */
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
  return shifted_char;
}

void shift_str_by(char* c, int by, char* shifted)
{
  int len = strlen(c);
  for (int i = 0; i < len; ++i)
  {
    shifted[i] = shift_by(c[i], by);
  }
}
