#ifndef C_CONSOLE_H
#define C_CONSOLE_H

extern int color;
extern int position;

extern char *error;
extern int error_message_color;

extern const int WIDTH;
extern const int HEIGHT;

extern char data[];
extern char *console[];

extern char command[];
extern char name[];

extern char *framebuffer;

extern const int COMMAND_N;
struct Command{
    char *command;
    void (*function)();
    char *info;
};
extern const struct Command COMMANDS[];

extern int file_index;
extern const int FILES_N;

struct File{
    char fileName[20];
    char content[25 * 80];
};
extern struct File files[];

extern int edit_mode;
#endif
