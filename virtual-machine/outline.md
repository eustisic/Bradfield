register	purpose
-------------------------------
A			general purpose
B			general purpose
C			general purpose
D			general purpose
E			general purpose
F			general purpose
EX 			extra
EXA 		extra
IP			instruction pointer
SP			stack pointer


instructions
op   val    usage    		      function
---------------------------------------------------------------------
HLT  ff      hlt 	 			      halts program
PSH  01      psh val  		    pushes <val> to stack
STR  02      pop 	 			      pops value from stack
ADD  03      add 	 			      adds top two vals on stack
SUB  04      sub              set reg1 = reg1 - reg2