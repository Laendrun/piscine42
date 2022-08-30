cat /etc/passwd | grep -v "^#" | awk 'NR%2==0' | cut -f1 -d":" | sort -r | rev | tail -n $FT_LINE1 | head -n $FT_LINE2 | tr '\n' ', '
