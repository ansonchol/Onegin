#ifndef MY_FILE_H
#define MY_FILE_H

size_t get_file_size(const char* file_name);
int split_buffer_into_arr_str(char* buffer, char** array_string, int max_lines);
int read_file_into_buffer(const char* file_name, char** array_string, size_t size, int max_lines);
void write_lines_to_file(const char* dst_file, char** array_string, int len_arr,  const char* mode);

#endif
