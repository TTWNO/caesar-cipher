#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"

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
  // if given a DECEASAR compile paramater, use a negative
  int shift;
#ifdef DECAESAR
  shift = -atoi(argv[1]);
#else
  shift = atoi(argv[1]);
#endif
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
