# Commonly Used Linux Commands

This `README.md` provides a collection of essential Linux commands that are frequently used for system navigation, file management, network operations, and process management. These commands are useful for beginners and intermediate users alike.

---

## Table of Contents

1. [File and Directory Management](#file-and-directory-management)
2. [File Permissions](#file-permissions)
3. [Process Management](#process-management)
4. [Disk Usage](#disk-usage)
5. [Package Management](#package-management)
6. [System Information](#system-information)
7. [Networking](#networking)
8. [Text Processing](#text-processing)
9. [Other Useful Commands](#other-useful-commands)

---

## File and Directory Management

- `pwd`  
  Displays the current working directory.

- `ls`  
  Lists the files and directories in the current directory.  
  Options:
  - `ls -l` for detailed information (permissions, owner, size, etc.)
  - `ls -a` to show hidden files

- `cd <directory>`  
  Changes the current directory to `<directory>`.

- `mkdir <directory>`  
  Creates a new directory named `<directory>`.

- `rmdir <directory>`  
  Removes an empty directory named `<directory>`.

- `rm <file>`  
  Removes a file named `<file>`.  
  Options:
  - `rm -r <directory>` to remove a directory and its contents
  - `rm -f <file>` to force delete without confirmation

- `cp <source> <destination>`  
  Copies a file or directory to the destination.

- `mv <source> <destination>`  
  Moves or renames a file or directory.

- `find <path> -name <pattern>`  
  Searches for files and directories matching `<pattern>` in the specified `<path>`.

---

## File Permissions

- `chmod <permissions> <file>`  
  Changes the permissions of a file.  
  Example: `chmod 755 <file>` gives read, write, and execute permissions to the owner, and read and execute permissions to others.

- `chown <user>:<group> <file>`  
  Changes the owner and group of a file.

- `ls -l <file>`  
  Displays detailed file information including permissions, owner, and group.

---

## Process Management

- `ps`  
  Displays the current running processes.

- `top`  
  Displays an interactive, real-time view of system processes.

- `kill <pid>`  
  Terminates the process with the specified `<pid>`.

- `killall <process_name>`  
  Terminates all processes with the specified name.

- `bg`  
  Resumes a suspended job in the background.

- `fg`  
  Brings a background job to the foreground.

---

## Disk Usage

- `df`  
  Displays disk space usage for all mounted filesystems.

- `du <directory>`  
  Shows the disk usage of a specified directory.

- `du -sh <directory>`  
  Shows the total size of the directory in a human-readable format.

- `mount <device> <mount_point>`  
  Mounts a filesystem.

- `umount <mount_point>`  
  Unmounts a filesystem.

---

## Package Management

### On Debian/Ubuntu-based systems

- `sudo apt update`  
  Updates the list of available packages.

- `sudo apt upgrade`  
  Upgrades all installed packages to their latest versions.

- `sudo apt install <package>`  
  Installs a package named `<package>`.

- `sudo apt remove <package>`  
  Removes the specified package.

### On Red Hat/CentOS/Fedora-based systems

- `sudo yum update`  
  Updates installed packages to the latest versions.

- `sudo yum install <package>`  
  Installs a package.

- `sudo yum remove <package>`  
  Removes the specified package.

---

## System Information

- `uname -a`  
  Displays detailed information about the system's kernel.

- `hostname`  
  Displays or sets the system's hostname.

- `uptime`  
  Shows how long the system has been running.

- `whoami`  
  Displays the current logged-in user.

- `free`  
  Displays memory usage statistics.

- `df -h`  
  Displays disk space usage in a human-readable format.

- `top`  
  Displays system resource usage, including CPU and memory usage.

---

## Networking

- `ping <host>`  
  Sends ICMP echo requests to a host to check connectivity.

- `ifconfig`  
  Displays or configures network interfaces.

- `ip addr`  
  Displays network interfaces and their IP addresses.

- `netstat`  
  Displays network connections, routing tables, interface statistics, etc.

- `curl <url>`  
  Transfers data from or to a server using various protocols (HTTP, FTP, etc.).

- `wget <url>`  
  Downloads content from the specified URL.

- `scp <source> <user>@<host>:<destination>`  
  Copies files securely between hosts.

---

## Text Processing

- `cat <file>`  
  Displays the content of a file.

- `more <file>`  
  Displays a file one screen at a time.

- `less <file>`  
  Allows for scrolling through the content of a file.

- `grep <pattern> <file>`  
  Searches for a pattern in a file.

- `sed`  
  Stream editor for filtering and transforming text.

- `awk`  
  A powerful text-processing tool for pattern scanning and processing.

- `sort <file>`  
  Sorts the contents of a file.

- `cut`  
  Removes sections from each line of files.

---

## Other Useful Commands

- `history`  
  Displays a list of previously executed commands.

- `man <command>`  
  Displays the manual page for a command.

- `clear`  
  Clears the terminal screen.

- `sudo <command>`  
  Executes a command as a superuser.

- `chmod +x <script>`  
  Makes a script file executable.

- `tar -czvf <archive.tar.gz> <file_or_directory>`  
  Creates a compressed archive file.

- `tar -xzvf <archive.tar.gz>`  
  Extracts the contents of a tar.gz archive.

---

## Conclusion

This document contains a set of commonly used Linux commands. Learning these commands will help you become more efficient at navigating and managing a Linux-based system. You can also refer to the `man` pages (`man <command>`) for more detailed information about each command.
