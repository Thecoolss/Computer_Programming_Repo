#include "uthash.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct map {
  char word[100];
  int freq;
  UT_hash_handle hh;
};
void perform_hash(const char *w, struct map **mp) {
  struct map *single;
  HASH_FIND_STR(*mp, w, single);
  if (single == NULL) {
    single = malloc(sizeof(*single));
    if (single == NULL) {
      perror("Memory Allocation Failed");
      return;
    }
    strcpy(single->word, w);
    single->freq = 1;
    HASH_ADD_STR(*mp, word, single);
  } else {
    single->freq++;
  }
}

void count_words(const char *text, struct map **mp) {
  if (text == NULL) {
    perror("Error with pointers");
    return;
  }
  int n = strlen(text);
  char temp[100];
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if ((text[i] == ' ' || text[i] == '\0') && cnt) {
      temp[cnt] = '\0';
      perform_hash(temp, mp);
      cnt = 0;
    } else {
      temp[cnt++] = text[i];
    }
  }
}

void readBook(const char *filename, char **contents) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }
  *contents = (char *)malloc((int)1e7 * sizeof(char));
  if (*contents == NULL) {
    perror("Memory allocation failed");
    return;
  }
  int cnt = 0;
  char c;
  while ((c = fgetc(file)) != EOF) {
    if (cnt == (int)(1e7 - 50)) {
      char *new_contents = (char *)realloc(*contents, (cnt * 2) * sizeof(char));
      if (new_contents == NULL) {
        perror("Memory Allocation Failes");
        free(*contents);
        return;
      }
      *contents = new_contents;
    }
    char prev_char =
        (cnt > 0) ? (*contents)[cnt - 1] : '\0'; 

    if (isalpha(c)) {
      (*contents)[cnt++] = tolower(c);
    } else {
   
      if (prev_char != ' ') {
        (*contents)[cnt++] = ' ';
      }
    }
    /*if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
      (*contents)[cnt++] = tolower(c);
    else
      (*contents)[cnt++] = ' ';*/
  }
  (*contents)[cnt] = '\0';
  fclose(file);
  // puts("ended function");
}

void print_words(const char *filename, struct map **mp) {
  FILE *wr_file = fopen(filename, "w");
  if (wr_file == NULL) {
    perror("Error opening file");
    return;
  }

  struct map *i;
  fprintf(wr_file,"Word Count\n");
  for (i = *mp; i != NULL; i = i->hh.next) {
    fprintf(wr_file, "%s %d\n", i->word, i->freq);
    if(i->freq==1)
      printf("Word: %s    Count: %d\n", i->word, i->freq);
  }
}

int main() {
  char *book_contents = NULL;
  struct map *mp = NULL;

  readBook("pg2701.txt", &book_contents);
  // printf("%c\n",book_contents[100]);
  count_words(book_contents, &mp);

  puts("Analysing done");
  print_words("word_counts.txt", &mp);
  free(book_contents);
  return 0;
}