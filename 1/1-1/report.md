# **Exercise 1-1.**
## Runn the `"hello, world"` program on your system. Experiment with leaving out parts of the program, to see what error messages you get. 

---

---

[working dir](.)

### Runing the program:

I am using the MinGW-w64 gcc compiler, so I will run the following command to compile:

	$ gcc -ansi hello.c

The defalt output program is `a.exe`. To run this program in git bash, use:

	$ ./a

Output:

	hello, world

Yay! 
<br>
<br>

### If the angle brackets are removed like so:

	/* hello.c */
	main()
	{
		printf("hello, world\n");
	}


---
	$ gcc -ansi hello.c

	hello.c:1:10: error: #include expects "FILENAME" or <FILENAME>
	 #include stdio.h
	          ^~~~~
	hello.c: In function 'main':
	hello.c:4:2: warning: incompatible implicit declaration of built-in function 'printf'
	  printf("hello, world\n");
	  ^~~~~~
	hello.c:4:2: note: include '<stdio.h>' or provide a declaration of 'printf'
	hello.c:1:1:
	+#include <stdio.h>
	 #include stdio.h
	hello.c:4:2:
	  printf("hello, world\n");
	  ^~~~~~



**explanaion:** omiting the angular brackets causes the `#include` to fail, and therefore causing a second error, because `printf` needs to be included.

**conclusion:** Don't forget angular brackets or quotes on includes. Don't forget to include functions from the standard library that your

**comment:** I love how the compiler tells you exactly how to fix your problems, he is si nice, compared to other laguages. If you are doing something wrong, 99% of the time all you have to do is read error messages to learn how to fix it/avoid doing it in the future
<br>
<br>

### If the `main` function is removed:

	#include <stdio.h>

	printf("hello, world\n");

---

	$ gcc -ansi hello.c
	hello.c:4:8: error: expected declaration specifiers or '...' before string constant
	printf("hello, world\n");
	        ^~~~~~~~~~~~~~~~

**explanaion:** The error isn't so clear this time, but what is happening is that all C programs need an entry point from where to start executing code, this is not automatic. This helps us understand  the difference between function declarations and deffenitions.

**conclusion:** All programs C start executing code in the `main()` function.
<br>
<br>

### If `printf()` is removed

	main()
	{
		printf("");
	}

---

This actualy compiles and "works"

	$ gcc -ansi hello.c

	$ ./a

However the output is just empty.
<br>
<br>

### If the quotes and their contents are removed

	/* hello.c */
	#include <stdio.h>

	main()
	{
		printf();
	}

---

	$ gcc -ansi hello.c
	hello.c: In function 'main':
	hello.c:7:2: error: too few arguments to function 'printf'
	  printf();
	  ^~~~~~
	In file included from hello.c:3:
	C:/mingw64/x86_64-w64-mingw32/include/stdio.h:509:15: note: declared here
	   int __cdecl printf(const char * __restrict__ _Format,...);

**explanaion:** This however doesn't work because `printf` needs an argument, even if an empty one.
<br>
<br>

### If the only quotes are removed

	/* hello.c */
	#include <stdio.h>

	main()
	{
		printf(hello, world\n);
	}

---

	$ gcc -ansi hello.c
	hello.c: In function 'main':
	hello.c:7:9: error: 'hello' undeclared (first use in this function); did you mean 'ftello'?
	  printf(hello, world\n);
	         ^~~~~
	         ftello
	 ...

**explanation:** this does not work because the quotes mean that the contents is a charecter string (text), otherwise it thinks it's code.
<br>
<br>

## Overal conclusion

It is posible to break the program in other ways, however I got boared. I think this is a great exercise in any programing language, espcialy for beginers to programing, as they (speaking from past experience) often forget what is the right way of doing things (e.g. forgeting a semicolon). Because this is a consiace exercise, this will help you remember what works, and moreover, understand preciesly what works and what doesn't.