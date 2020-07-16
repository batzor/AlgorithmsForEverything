#!/bin/bash
gpg --import public_key.pgp 2> /dev/null && cat signed_msg.asc | echo $(gpg -d 2>/dev/null)
