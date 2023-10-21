#include "kernel/kernel.h"
#include "drivers/keyboard/keyboard.h"
#include "drivers/timer/timer.h"
#include "drivers/serial_port/serial_port.h"

#include "mylib/console/console.h"
#include "mylib/console/input/input.h"
#include "mylib/console/commands/commands.h"

void exception_handler(u32 interrupt, u32 error, char *message) {
    serial_log(LOG_ERROR, message);
}
void init_kernel() {
    init_gdt();
    init_idt();
    init_exception_handlers();
    init_interrupt_handlers();
    register_timer_interrupt_handler();
    register_keyboard_interrupt_handler();
    configure_default_serial_port();
    set_exception_handler(exception_handler);
    enable_interrupts();
}

_Noreturn void halt_loop(){
    while (1) { halt(); }
}

void key_handler(struct keyboard_event event){
    if (event.type == EVENT_KEY_PRESSED) {
        if (event.key == KEY_BACKSPACE) {
            backspace();
        } else if (event.key == KEY_ENTER) {
            enter();
        } else {
            key(event.key_character);
        }
    }
}

void timer_tick_handler(){
}

void kernel_entry(){
    init_kernel();
    keyboard_set_handler(key_handler);
    timer_set_handler(timer_tick_handler);
    clear();
}
