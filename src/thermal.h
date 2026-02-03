#ifndef THERMAL_H
#define THERMAL_H

float read_temperature(void);
int check_threshold(float temp, int threshold);
void log_temperature(float temp);

#endif
