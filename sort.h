#ifndef SORT
#define SORT

void print_massive(void* s,      size_t size,   int    len_massive, void (*Func)(const void* value));
void sort_bubble  (void* data,   size_t size,   int    len_s,       int  (*CompareFunc)(const void* a, const void* b));
void switch_value (void* value1, void*  value2, size_t size);

//comparator for sort
int Int_Compare_Up   (const void* a, const void* b);
int Int_Compare_Down (const void* a, const void* b);
int Char_Compare_Up  (const void* a, const void* b);
int Char_Compare_Down(const void* a, const void* b);
int CharPtr_Compare_Up(const void* a, const void* b);
int CharPtr_Compare_Down(const void* a, const void* b);

//comparator for print_massive
void Print_Int(const void* value);
void Print_Char(const void* value);

#endif
