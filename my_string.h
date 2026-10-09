#ifndef MY_STRING_H
#define MY_STRING_H

// void print_massive_string(char** s, int size_x);
int my_strlen(const char* s);
void my_puts(const char* s);
char* my_strcpy(char* s1, const char* s2);
char* my_strcat(char* s1, const char* s2);
bool is_letter(char sym);
int to_upper_letter(char s1);
int my_strcmp(const char* s1, const char* s2); //1 - первое второе раньше, -1 - первое раньше
int my_strcmp_reverse(const char* s1, const char* s2);

#endif


