#include "thermal.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>

float read_temperature(void) {
    FILE* file;
    char path[MAX_TEMP_PATH];
    float temp;
    
    snprintf(path, sizeof(path), "/sys/class/thermal/thermal_zone0/temp");
    file = fopen(path, "r");
    if (!file) return -1;
    
    fscanf(file, "%f", &temp);
    fclose(file);
    return temp / 1000.0;
}

int check_threshold(float temp, int threshold) {
    if (temp > threshold) return 1;
    return 0;
}

void log_temperature(float temp) {
    FILE* log = fopen(LOG_FILE, "a");
    if (log) {
        fprintf(log, "Temperature: %.1f°C\n", temp);
        fclose(log);
    }
}
