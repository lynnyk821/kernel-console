#ifndef C_OTH_H
#define C_OTH_H

extern int length(char *data);
extern int equals(char *str1, char *str2);
extern char *copy_from(char *data, int left_index, int m);
extern void clear_array(char *array, int n);
extern void put_cursor(unsigned short pos);
extern void append_str(char *str, char c);

struct Separator{
    char *data;
};
extern struct Separator separators[];

#endif
