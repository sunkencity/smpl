#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 * A simple utility to sample a file
 * Doesn't count lines in advance so percentage is uneven at low volumes and approximate at best
 * usage smpl %1 foobar
 *
 */

int percentage = 1;

int should_print() {
  int random_number = rand() % 100 + 1;
  return (random_number <= percentage);
}

int main (int argc, char *argv[]) {

  int i;
  srand (time(0));

  if (argc > 1) {
    if (argv[1][0] == '%') {
      char * p = (char*) argv[1];
      p++;
      percentage = atoi(p);
      if (percentage > 100) {
        fprintf(stderr,"The percent is: %d\n", percentage);
        fputs("Percentage is too high, exiting...",stderr);
        exit(1);
      } else if (percentage < 1) {
        fprintf(stderr,"The percent is: %d\n", percentage);
        fputs("Percentage is too small, exiting...",stderr);
        exit(1);
      }
    }
  } else {
    fputs("Utility to sample a percentage of lines from a file\n",stderr);
    fputs("Unreliable percentage with low number of lines\n",stderr);
    fputs("usage: smpl %4 <files...>\n",stderr);
    fputs("or read from stdin: smpl %4",stderr);
    exit(1);
  }

  if (argc > 2) {
    for (i = 2;i<argc;i++) {

      FILE *file = fopen(argv[i], "r");
      if (file != NULL) {
        char line [2048];
        while (fgets(line, sizeof line, file) != NULL) {
          if (should_print()) {
            fputs(line,stdout);
          }
        }
        fclose(file);
      } else {
        perror (argv[i]);
      }
    }
  } else {
    char line [2048];
    while (fgets(line, sizeof line, stdin) != NULL) {
      if (should_print()) {
        fputs(line,stdout);
      }
    }
  }

}
