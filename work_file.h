#ifndef MY_FILE_H
#define MY_FILE_H

size_t file_size(const char* file_name);
int move_massive_to_buffer(char* fp, char** buffer);
int open_file_to_buffer(const char* file_name, char** buffer, size_t size);
void write_edit_file(const char* file_edit, char** buffer, int len_buf);

#endif
