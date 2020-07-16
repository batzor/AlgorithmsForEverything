#!/bin/bash

echo "Starting!"
total=$(wc -l /usr/share/dict/words | cut -f 1 -d ' ')
echo "the linux dict has $total words"
i=0
while read f; do
    i=$((i + 1))
    echo -ne "Checking $i/$total"\\r
    if echo "$f" | gpg -d --batch --yes --passphrase-fd 0 signed_msg.asc 2>/dev/null; then
        echo " is the answer and the password is $f"
        break
    fi
done </usr/share/dict/words
