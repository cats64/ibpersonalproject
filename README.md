# Nathaniel's IB Personal Project
My entry for the IB Personal Project.
## General Q&A
### What is this?
This is a small kernel for i686 machines. It (will eventually) take input, print to the screen, and begin the rough sillouette of an operating system.
### How can I test it?
You'll need to build a cross compiler. I will add instructions on how to do that shortly, but please be warned that it is time consuming.
### What do the directories mean?
The kernel directory is for the kernel. The libc is baked into the kernel, but is made separate so that they do not interfere with each other. All documentation is in the docs directory. 

## Build problems
### How do I... 
### start the build process?
'./build.sh' or './build.sh -k' for multithreaded systems. 
### clean up the folder?
'./clean.sh' 
### run it in QEMU?
'./qemu.sh'. You need a copy of 'qemu-system-i386'. Qemu.sh will tell you before you run it if you have it installed. 
