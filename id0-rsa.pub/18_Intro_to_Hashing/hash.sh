#!/bin/bash

printf "id0-rsa.pub" | sha256sum | cut -f 1 -d ' ' | xargs printf | md5sum | cut -f 1 -d ' '
