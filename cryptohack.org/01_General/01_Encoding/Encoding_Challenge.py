import telnetlib
import json
from codecs import decode, encode
import base64
from Crypto.Util.number import long_to_bytes

HOST = "socket.cryptohack.org"
PORT = 13377

tn = telnetlib.Telnet(HOST, PORT)

def readline():
    return tn.read_until(b"\n")

def json_recv():
    line = readline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    tn.write(request)


for i in range(100):
    received = json_recv()
    print(received)

    encoding = received["type"]
    encoded = received["encoded"]

    if encoding == "base64":
        decoded = base64.b64decode(encoded).decode()
    elif encoding == "hex":
        decoded = decode(encoded, "hex").decode()
    elif encoding == "rot13":
        decoded = decode(encoded, 'rot_13')
    elif encoding == "bigint":
        decoded = decode(long_to_bytes(int(encoded, 0)))
    elif encoding == "utf-8":
        decoded = "".join(chr(o) for o in encoded)

    print("{}: {}".format(i, decoded))
    to_send = {
        "decoded": decoded
    }
    json_send(to_send)

print(json_recv())
