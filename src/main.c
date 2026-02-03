#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "thermal.h"
#include "config.h"

int running = 1;

void handle_signal(int sig) {
    running = 0;
}

int main(void) {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    
    while (running) {
        float temp = read_temperature();
        
        if (temp < 0) {
            printf("Error reading temperature\n");
            break;
        }
        
        printf("CPU Temp: %.1f°C\n", temp);
        log_temperature(temp);
        
        if (check_threshold(temp, DEFAULT_THRESHOLD)) {
            printf("WARNING: Temperature exceeds threshold!\n");
        }
        
        sleep(POLL_INTERVAL);
    }
    
    return 0;
}
