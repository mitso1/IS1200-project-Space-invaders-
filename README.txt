instructions for compiling and running code:

To compile and run the code you will need to use the 
MSYS MINGW64 or MSYS MINGW32 software development enviroments.
Your chipkit must be connected to your computer through USB.
Open the file directory through commands in MINGW (make sure project 
is located in msys64/dev), then when you are at 'IS2000-project' 
write "make", this should compile the code.
if the code compiles without any errors, you can then write 
"make install" which will then upload the code to the chipkit 
(this step can take some time).


COPYING: 

Copyright (c) 2015, Axel Isaksson
Copyright (c) 2015, F Lundevall

If you're a student, and you have modified one or more files,
you must add your name here.

Copyright (c) 2024, Adam Brolin
Copyright (c) 2024, Athanasios Kotronias

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the author may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.