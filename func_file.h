#ifndef MY_FILE_H
#define MY_FILE_H

size_t file_size(const char* file_name);
int ParseBufToArr(char* fp, char** buffer);
int ParseBuffFromFile(const char* file_name, char** buffer, size_t size);
void write_edit_file(const char* file_edit, char** buffer, int len_buf);

#endif
