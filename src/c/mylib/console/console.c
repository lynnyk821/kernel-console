#include "console.h"
#include "commands/commands.h"

int position = 0;
int color = 0xa;

char *error = "Undefined command";
int error_message_color = (int)0x5;

const int WIDTH = 80;
const int HEIGHT = 25;

char data[80 * 25];
char *console[25];

char command[10];
char name[20];

char *framebuffer = (char *)0xb8000;

const int COMMAND_N = 7;
const struct Command COMMANDS[] = {
        {"help", help, "help - help function"   },

        {"clear",clear, "clear - clear function" },
        {"list", list,  "list - list function"  },

        {"create", _create, "create - file create function" },
        {"delete", _delete, "delete - file delete function" },
        {"read",   _read,   "read - file read function"   },
        {"edit",   _edit,   "edit - file edit function"   },
};

int file_index = 0;
const int FILES_N = 10;
struct File files[10];

int edit_mode = 0;





