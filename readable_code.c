#include <stdlib.h>
#include <stdio.h>

int tabdepth;

int main() {
  tabdepth = 0;
  char fname[100];
  int stop = 1;
  FILE *source;
  while (stop) {
    printf("Enter file name: ");
    scanf("%s", fname);
    printf("fname = %s\n", fname);
    source = fopen(fname, "r");
    if (!source) {
      printf("Please enter a valid filename\n");
    }
    else {
      stop = 0;
    }
  }
  
  FILE *output = fopen("output", "w+");

  int c = fgetc(source);
  int i;
  while (c && c != EOF) {
    switch (c) {
    case '{':
      // } and newline
      fputc(c, output);
      fputc('\n', output);
      //increment tabdepth
      tabdepth++;
      //output the tab
      i = 0;
      for (; i < tabdepth; i++) {
	fputc('\t', output);
      }
      break;
    case '}':
      //decrement tabdepth
      tabdepth--;
      // newline, tabs, }
      fputc('\n', output);
      i = 0;
      for (;i < tabdepth; i++) {
	fputc('\t', output);
      }
      fputc(c, output);
      break;
    default:
      fputc(c, output);
    }
    c = fgetc(source);
    //printf("char = %c\n", c);
  }
  fclose(output);
  fclose(source);
}
