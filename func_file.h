#ifndef MY_FILE_H
#define MY_FILE_H

size_t get_file_size(const char* file_name);
int split_buffer_into_arr_str(char* buffer, char** array_string, int size_buf);
int read_file_into_buffer(const char* file_name, char** array_string, size_t size);
void write_lines_to_file(const char* dst_file, char** array_string, int line, const char* mode);

#endif
