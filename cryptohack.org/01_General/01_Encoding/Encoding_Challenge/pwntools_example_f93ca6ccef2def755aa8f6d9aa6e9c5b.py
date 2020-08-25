from pwn import * # pip install pwntools
import json
import base64

r = remote('socket.cryptohack.org', 13377, level = 'debug')

def json_recv():
    line = r.recvline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)


for i in range(100):
    received = json_recv()

    encoding = received["type"]
    encoded = received["encoded"]

    if encoding == "base64":
        encoded = base64.b64decode(self.challenge_words.encode()).decode() # wow so encode
    elif encoding == "hex":
        encoded = self.challenge_words.encode().hex()
    elif encoding == "rot13":
        encoded = codecs.encode(self.challenge_words, 'rot_13')
    elif encoding == "bigint":
        encoded = hex(bytes_to_long(self.challenge_words.encode()))
    elif encoding == "utf-8":
    if(received[type])
    to_send = {
        "decoded": "changeme"
    }
    json_send(to_send)

json_recv()
