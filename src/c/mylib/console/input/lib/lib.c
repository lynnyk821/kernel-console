#include "../../console.h"
#include "../../../linq/linq.h"

void set_data(char key){
    data[position % WIDTH] = key;
}
void next_row(int length){
    framebuffer += 2 * (WIDTH - length); // skip row with data
    position += WIDTH - length; // position changes
    put_cursor(position); // put cursor in position
}
void split_data(char ch){
    int flag = 0;
    for(int i = 0, c = 0, n = 0; i < length(data); i++){
        if(data[i] == ch && flag != 1){
            flag = 1;
            i++;gi
        }
        if(flag == 0){
            command[c++] = data[i];
        } else{
            name[n++] = data[i];
        }
    }
}
void clear_input_data(){
    clear_array(data, WIDTH * HEIGHT);
    clear_array(command, 10);
    clear_array(name, 20);
}

