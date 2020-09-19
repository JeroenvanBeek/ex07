/*****************************************************************************
 * File:         filter.c
 * Version:      1.3
 * Date:         2012-02-04, 2016-04-28, 2017-12-12, 2018-04-25
 * Author:       M. van der Sluys, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  Read input from stdin, convert lower-case characters to 
 *               upper case and write result to stdout.
 *               Use file descriptors and process one character at a time (read()/write()).
 ******************************************************************************/

#include <unistd.h>  // read(), write()
#include <ctype.h>   // toupper()

#define ESC 0x1B

int main(void) {
  char letter;
  
  read(0, &letter, 1);          // read first char from stdin
  
  while(letter != ESC) {        // ESC = Ctrl-[ in shell
    letter = toupper(letter);   // convert to upper case
    write(1, &letter, 1);       // write char to stdout
    read(0, &letter, 1);        // read next char from stdin
  }
  return 0;
}
