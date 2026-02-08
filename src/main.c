#include <stdio.h>
#include "config.h"
#include "thermal.h"

enum tempguard_exit_code {
    EXIT_OK = 0,
    EXIT_WARNING = 1,
    EXIT_CRITICAL = 2
};

static enum tempguard_exit_code classify_temperature(float temp_c) {
    if (temp_c >= TEMP_CRITICAL_C) {
        return EXIT_CRITICAL;
    }

    if (temp_c >= TEMP_WARNING_C) {
        return EXIT_WARNING;
    }

    return EXIT_OK;
}

int main(void) {
    float temp_c = 0.0f;
    enum tempguard_exit_code status = EXIT_WARNING;

    if (thermal_read_celsius(&temp_c) != 0) {
        printf("WARNING: unable to read temperature from %s\n", thermal_sensor_label());
        return EXIT_WARNING;
    }

    status = classify_temperature(temp_c);
    switch (status) {
    case EXIT_CRITICAL:
        printf("CRITICAL: %s temperature %.1f°C\n", thermal_sensor_label(), temp_c);
        break;
    case EXIT_WARNING:
        printf("WARNING: %s temperature %.1f°C\n", thermal_sensor_label(), temp_c);
        break;
    case EXIT_OK:
    default:
        printf("OK: %s temperature %.1f°C\n", thermal_sensor_label(), temp_c);
        break;
    }

    return status;
}
