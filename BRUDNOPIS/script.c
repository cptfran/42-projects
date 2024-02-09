// '#!'- declaring interpreter used to execute script ('#' - this is just comment)
#!/bin/bash

# ARCH // comment describing the section
arch=$(uname -a) // 'arch' - variable '$' - execute 'uname' - tool giving information about system '-a' - gives information about kernel

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l) // 'grep' - for searching text, finds all lines with "physical id" in file /proc/cpuinfo
// 'wc' - counts lines/signs/words

# VCPU
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# MEMORY USAGE
ram_total=$(free -m | awk '$1 == "Mem:" {print $2}') // 'free' - displays amount of available and used memory in OS
ram_use=$(free -m | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free -m | awk '$1 == "Mem:" {printf("%.2f", $2/$3*100)}')	
// '--mega' - displays memory in MB 'awk' - tool for text processing

# DISK USAGE
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGB\n", disk_t/1024)}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} {disk_u += $3} END {printf("%d", disk_u/disk_t*100)}')
// 'df -m' - information about disk in megabytes
// 'grep "/dev/"' - filters only lines including information about disks
// 'grep -v "/boot"' - excludes all lines with /boot partition
// END - to calculate awk variables

# CPU LOAD
cpul=$(vmstat | tail -1 | awk '{printf $15}') // 'vmstat' - tool to monitor system '1 2' - means vmstat should generate 2 reports in 1 second
// 'tail' - displays last lines of the file 'tail -1' - displays only last line
cpu_op=$(expr 100 - $cpul) // 'expr' - used to make calculations and print the result 'cpu_op' - czas bezczynności procesora(cpu idle time)
cpu_fin=$(printf "%.1f" $cpu_op)

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}') // 'who' - displays info about currend logged users 'who -b' - only from last boot

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
// 'lsblk' - displays info about block devices (disks, partitions)
// 'lvm' - logical volume manager - allows to better manage disk space
// '-gt' greater than	

# TCP CONNECTIONS//	tcp - transmission control protocol
tcpc=$(ss -ta | grep ESTAB | wc -l) // 'ss' -for about network sockets '-t'only about TCP sockets
// 'a' - tells to display info about all sockets, closed and opened, without it displays only opeend so tool to display inckets
// 'ESTAB' - shows only ESTABLISHED connetions

# USER LOG
ulog=$(users | wc -w)  // 'users' - displays names of users that are currently logged in
// 'wc -w' - counts amount of words

# NETWORK
ip=$(hostname -I) // 'hostname' - return system name 'hostname -I' - returns all network IP addresses
mac=$(ip link | grep "link/ether" | awk '{print $2}') // 'ip link' - displays all available network interfaces and their addresses
// 'link/ether' - displays only mac addresses

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
// 'journalctl _COMM=sudo' - returns all entries in system journal with command sudo
// 'grep COMMAND' - returns only lines with word "COMMAND"
