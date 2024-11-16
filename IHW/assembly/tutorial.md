1. Compile o programa:

2. Linke o arquivo objeto:

3. ./hello

nasm -f elf32 hello.asm && ld -m elf_i386 -o hello hello.o && ./hello

spim -f hello.asm && spim -file hello.asm

