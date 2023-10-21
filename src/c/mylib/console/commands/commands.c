#include "commands.h"
#include "../console.h"
#include "../../linq/linq.h"
#include "../output/output.h"

int is_single_command(){
    return length(name) == 0 ? 1 : 0;
}
void help(){
    if(is_single_command()){
        println("", color);
        for(int i = 0; i < COMMAND_N + 1; i++){
            if(!equals(COMMANDS[i].command, "help")){
                println(COMMANDS[i].info, color);
            }
        }
        return;
    }
    println(error, error_message_color);
}
void clear(){
    if(is_single_command()){
        fill_console('\0');
        framebuffer -= 2 * position;
        put_cursor(0);
        position = 0;
        return;
    }
    println(error, error_message_color);
}

void list(){
    if(is_single_command()){
        for(int i = 0; i < FILES_N; i++){
            if(!equals(files[i].fileName, "")){
                println(files[i].fileName, color);
            }
        }
        return;
    }
    println(error, error_message_color);
}

// File commands

void _create(){
    if(file_index < FILES_N){
        if(!is_single_command() && name[0] != ' '){
            for(int i = 0; i < FILES_N; i++){
                if(equals(files[i].fileName, name)){
                    println("The file already exists", error_message_color);
                    return;
                }
            }
            for(int i = 0; i < length(name); i++)
                files[file_index].fileName[i] = name[i];
            println("File created!", color);
            file_index++;
        }
        else{
            println("Enter file name!", error_message_color);
        }
    }
    else{
        println("Number of files exceeded!", error_message_color);
    }
}
void _delete(){
    if(file_index > 0){
        for(int i = 0; i < FILES_N; i++){
            if(equals(files[i].fileName, name)){
                clear_array(files[i].fileName, 20);
                clear_array(files[i].content, WIDTH * HEIGHT);
            }
        }
    }
}

void _edit(){
    if(!is_single_command() && name[0] != ' '){
        edit_mode = 1;
        for(int i = 0; i < FILES_N; i++){
            if(equals(files[i].fileName, name)){
                clear();
                for(int j = 0; j < WIDTH * HEIGHT; j++)
                    files[i].content[j] = data[j];
                return;
            }
            println("File does not exist", error_message_color);
        }
    }else{
        println("Enter file name!", error_message_color);
    }
}
void _read(){
    if(!is_single_command() && name[0] != ' '){
        for(int i = 0; i < FILES_N; i++){
            if(equals(files[i].fileName, name)){
                println(files[i].content, color);
                return;
            }
            println("File does not exist", error_message_color);
        }
    }else{
        println("Enter file name!", error_message_color);
    }

}


