![TempGuard Banner](assets/banner.png)
# TempGuard

TempGuard is a small Linux CLI tool written in C that reads CPU temperature from sysfs and returns Nagios-style status output (`OK`, `WARNING`, `CRITICAL`) with matching exit codes.

## Build

Requirements:
- GCC or compatible C compiler
- GNU Make
- Linux system exposing thermal data under `/sys/class/thermal`

Build release binary:

```bash
make
```

Build debug binary:

```bash
make debug
```

Clean build artifacts:

```bash
make clean
```

## Usage

Run the tool:

```bash
./tempguard
```

Or use the make target:

```bash
make run
```

Typical output:

- `OK: cpu-thermal temperature 52.3°C`
- `WARNING: cpu-thermal temperature 84.0°C`
- `CRITICAL: cpu-thermal temperature 91.2°C`
- `WARNING: unable to read temperature from cpu-thermal` (sensor read failed)

Exit codes:

- `0` = OK
- `1` = WARNING (including read failures)
- `2` = CRITICAL
