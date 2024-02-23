#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "revwords.h"

int string_length(char s[]) {
    int i = 0;
    while (s[i] != '\0') { 
        i++;
    }
    return i; 
}

void reverse_substring(char str[], int start, int end) { 
  /* TODO */
  printf("Len: %d\n", end-start+1);
  int len = end-start+1;
  char new[len];
  for (int i = 0; i < len; i++)
  {
    new[len - i - 1] = str[start + i];
  }  
  for (int i = start; i < end + 1; i++)
  {
    str[i] = new[i-start];
  }
}

int find_next_start(char str[], int len, int i) { 
  /* TODO */
  while (!isalpha(str[i]) && i < len) {i ++;}
    return i < len ? i : -1; // Return -1 if no more starts are found 
}

int find_next_end(char str[], int len, int i) {
  /* TODO */
  while (((65 <= str[i] && str[i] <= 90) || (97 <= str[i] && str[i] <= 122)) && str[i] != '\0') 
  { i ++; }
  return i - 1;
}

void reverse_words(char s[]) {
    int len = string_length(s); // Using strlen from string.h for simplicity
    int cur_start = find_next_start(s, len, 0);
    
    while (cur_start != -1 && cur_start < len) {
        int end = find_next_end(s, len, cur_start);
        reverse_substring(s, cur_start, end);
        cur_start = find_next_start(s, len, end + 1);
    }
}