# Security Policy

## Scope

TempGuard is a local, read-only CPU temperature monitoring tool for Linux.
It does not:
- expose network services
- handle untrusted remote input
- require elevated privileges by design

Security considerations mainly involve:
- memory safety
- local file parsing
- unexpected system configurations

## Supported Versions

Only the latest release on the `main` branch is supported.

## Reporting a Vulnerability

If you believe you have found a security-related issue such as:
- buffer overflows
- memory corruption
- crashes caused by malformed system data
- privilege escalation risks

please do **not** open a public issue.

Instead, report it via GitHub Security Advisories or contact the maintainer privately.

Non-security bugs should be reported using regular GitHub Issues.
