#include "lib/lib.h"
#include "../console.h"
#include "../../linq/linq.h"
#include "../output/output.h"

void key(char key){
    framebuffer[0] = key;
    framebuffer[1] = color;
    framebuffer += 2;
    set_data(key);
    put_cursor(++position);
}

void backspace(){
    if(position % WIDTH > 0){
        framebuffer -= 2;
        framebuffer[0] = '\0';
        set_data('\0');
        put_cursor(--position);
    }
}

void enter(){
    next_row(length(data));
    if(edit_mode == 0){
        split_data(' ');
        for (int i = 0; i < COMMAND_N; i++) {
            if (equals(command, COMMANDS[i].command)) {
                COMMANDS[i].function();
                clear_input_data();
                return;
            }
        }
        clear_input_data();
        println(error, error_message_color);
    } else {
        edit_mode = 0;
    }
}


