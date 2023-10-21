#include "linq.h"
#include "../../kernel/kernel.h"

int length(char *message){
    int length = 0;
    while (message[length] != '\0'){
        length++;
    }
    return length;
}

int equals(char *str1, char *str2){
    while (*str1 != '\0' && *str2 != '\0'){
        if (*str1 != *str2) return 0;
        str1++; str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}
void clear_array(char *array, int n){
    for(int i = 0; i < n; i++){
        array[i] = '\0';
    }
}

void append_str(char* str, char c) {
    int len = length(str);
    str[len] = c;
    str[len + 1] = '\0';
}
char* copy_from(char *data, int left_index, int right_index){
    char *new_data = "";
    for(int i = left_index; i <= right_index; i++)
        append_str(new_data, data[i]);
    return new_data;
}

void put_cursor(unsigned short pos) {
    out(0x3D4, 14);
    out(0x3D5, ((pos >> 8) & 0x00FF));
    out(0x3D4, 15);
    out(0x3D5, pos & 0x00FF);
}
