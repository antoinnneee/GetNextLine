
VAR=$(cat /proc/sys/fs/file-max)

sed -i "s/FDMAX.*/FDMAX $VAR/" get_next_line.h
