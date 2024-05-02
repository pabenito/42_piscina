cat /etc/passwd | fgrep -v '#' | awk '(NR % 2 == 0)' | cut -d : -f 1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed 's/,$/./'  | sed 's/,/, /g' | tr -d '\n'
