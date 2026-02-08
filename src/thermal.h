#ifndef THERMAL_H
#define THERMAL_H

int thermal_read_celsius(float *out_temp_c);
const char *thermal_sensor_label(void);

#endif
