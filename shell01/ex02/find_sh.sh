find . -type f -name "*.sh" | sed -e "s/^\.\///g" | sed "s/\.sh//"
