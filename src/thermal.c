#include <stdio.h>
#include "config.h"
#include "thermal.h"

typedef int (*thermal_read_fn)(float *out_temp_c);

struct thermal_backend {
    const char *label;
    thermal_read_fn read_temp_c;
};

static int read_sysfs_temp(float *out_temp_c) {
    char path[MAX_TEMP_PATH];
    FILE *file = NULL;
    long temp_milli = 0;
    int scanned = 0;

    if (!out_temp_c) {
        return -1;
    }

    snprintf(path, sizeof(path), SYSFS_TEMP_PATH_FORMAT, SYSFS_THERMAL_ZONE);
    file = fopen(path, "r");
    if (!file) {
        return -1;
    }

    scanned = fscanf(file, "%ld", &temp_milli);
    fclose(file);
    if (scanned != 1) {
        return -1;
    }

    *out_temp_c = (float)temp_milli / 1000.0f;
    return 0;
}

static const struct thermal_backend SYSFS_BACKEND = {
    .label = SENSOR_LABEL,
    .read_temp_c = read_sysfs_temp,
};

static const struct thermal_backend *ACTIVE_BACKEND = &SYSFS_BACKEND;

int thermal_read_celsius(float *out_temp_c) {
    if (!ACTIVE_BACKEND || !ACTIVE_BACKEND->read_temp_c) {
        return -1;
    }

    return ACTIVE_BACKEND->read_temp_c(out_temp_c);
}

const char *thermal_sensor_label(void) {
    if (!ACTIVE_BACKEND || !ACTIVE_BACKEND->label) {
        return "unknown-sensor";
    }

    return ACTIVE_BACKEND->label;
}
