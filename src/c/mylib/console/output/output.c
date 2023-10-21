#include "../../linq/linq.h"
#include "../console.h"
#include "output.h"

void fill_console(char ch){
    char *tmp_buffer = (char *)0xb8000;
    for(int i = 0; i < WIDTH * HEIGHT; i++){
        tmp_buffer[0] = ch;
        tmp_buffer[1] = color;
        tmp_buffer += 2;
    }
}

void print(char *message, int p_color){
    for(int i = 0; i < length(message); i++){
        framebuffer[0] = message[i];
        framebuffer[1] = p_color;
        framebuffer += 2;
        position++;
    }
}

void println(char *message, int p_color){
    int len_message = WIDTH - length(message);
    print(message, p_color);
    framebuffer += 2 * len_message;
    position += len_message;
    put_cursor(position);
}
