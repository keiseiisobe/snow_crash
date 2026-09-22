import struct
import socket

SOCK_PATH="/run/blacksun/blacksun.sock"

def compute_checksum(payload):
    checksum = 0
    for i, b in enumerate(payload):
        checksum ^= b ^ (i & 0xFF)
    return checksum

def main():
    version = 1
    state = 1
    payload = bytes([0xAD, 0xDE] + [0x00] * 30) # first two bytes of MAGIC_HELLO which is compared in CMD_HELLO
    length = len(payload)
    checksum = compute_checksum(payload) # same logic as blacksun.c

    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    s.connect(SOCK_PATH)

    for cmd in range(0, 3):
        header_1 = (version & 0x07) | ((state & 0x03) << 3) | ((cmd & 0x07) << 5) # Bits-Fields Pack
        header_2 = length
        header_3 = checksum
        header = struct.pack("<BIHx", header_1, header_2, header_3) # reference https://docs.python.org/fr/3.5/library/struct.html to understand "<BIHX" 
        data = header + payload
    
        s.sendall(data)

        response = s.recv(1024)
        print(response.decode(errors="replace"))
    s.close()
    return

main()
