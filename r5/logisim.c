#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

int A, B, C, D, E, F, G, X, Y, X1, Y1;

void run_logic(void) {
  X1 = !X && Y;
  Y1 = !X && !Y;
  A = (!X && !Y) || (X && !Y);
  B = 1;
  C = (!X && !Y) || (!X && Y);
  D = (!X && !Y) || (X && !Y);
  E = (!X && !Y) || (X && !Y);
  F = (!X && !Y);
  G = (X && !Y);
  X = X1;
  Y = Y1;
}

void show(void) {
  static const char template[] = "   AAAAAAAAA\n"
                                 "  FF       BB\n"
                                 "  FF       BB\n"
                                 "  FF       BB\n"
                                 "  FF       BB\n"
                                 "   GGGGGGGGG\n"
                                 "  EE       CC\n"
                                 "  EE       CC\n"
                                 "  EE       CC\n"
                                 "  EE       CC\n"
                                 "   DDDDDDDDD\n";
  static int *outs[] = {&A, &B, &C, &D, &E, &F, &G};
  static char on = 'o', off = ' ';

  printf("\033[2J\033[1;1f"); // clear
  for (size_t i = 0; i != sizeof(template); ++i) {
    if ('A' <= template[i] && template[i] <= 'G') {
      if (*outs[template[i] - 'A'])
        printf("\033[31m%c\033[0m", on);
      else
        printf("\033[37m%c\033[0m", off);
    } else
      putchar(template[i]);
  }
  fflush(stdout);
}

int main(void) {
  while (1) { // clock
    run_logic();
    show();
    sleep(1);
  }
  return 0;
}
