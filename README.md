# Nathaniel's IB Personal Project
My entry for the IB Personal Project.
## General Q&A
### What is this?
This is a small kernel for i686 machines. It (will eventually) take input, print to the screen, and begin the rough sillouette of an operating system.
### How can I test it?
You'll need to build a cross compiler. I will add instructions on how to do that shortly, but please be warned that it is time consuming.
### What do the directories mean?
The kernel directory is for the kernel. The libc is baked into the kernel, but is made separate so that they do not interfere with each other. All documentation is in the docs directory. 
### I don't want to build it. Where can I get an ISO?
There will be ISOs eventually in a sub-directory. 

## Build problems
### How do I build it?
Run build.sh, then run qemu.sh to start it in QEMU. Alternatively, run build.sh and then iso.sh to make an ISO file.
