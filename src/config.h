#ifndef CONFIG_H
#define CONFIG_H

#define SENSOR_LABEL "cpu-thermal"
#define SYSFS_THERMAL_ZONE "thermal_zone0"
#define SYSFS_TEMP_PATH_FORMAT "/sys/class/thermal/%s/temp"
#define MAX_TEMP_PATH 256

#define TEMP_WARNING_C 80.0f
#define TEMP_CRITICAL_C 90.0f

/* Future extensions:
 * - Additional sensor labels/zones (GPU, NVMe).
 * - JSON output configuration.
 */

#endif
