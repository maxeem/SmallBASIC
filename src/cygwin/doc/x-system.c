char *help_page_c=
">> System\n"
"_______________________________________________________________________\n"
"\n"
"${key:fre}\n"
"FRE(x)\n"
"\n"
"Returns system information\n"
"\n"
"Where x:\n"
"\n"
"QB-standard:\n"
"  0 - free memory\n"
" -1 - largest block of integers\n"
" -2 - free stack\n"
" -3 - largest free block\n"
"\n"
"Our standard (it is optional for now):\n"
"-10 - total physical memory\n"
"-11 - used physical memory\n"
"-12 - free physical memory\n"
"\n"
"Optional-set #1:\n"
"-13 - shared memory size\n"
"-14 - buffers\n"
"-15 - cached\n"
"-16 - total virtual memory size\n"
"-17 - used virtual memory\n"
"-18 - free virtual memory\n"
"\n"
"Optional-set #2:\n"
"-40 - battery voltage * 1000\n"
"-41 - battery percent\n"
"-42 - critical voltage value (*1000)\n"
"-43 - warning voltage value (*1000)\n"
"\n"
"The optional values will returns 0 if are not supported.\n"
"_______________________________________________________________________\n"
"\n"
"${key:ticks}\n"
"TICKS() \n"
"\n"
"Returns the system-ticks. The tick value is depended on operating\n"
"system. \n"
"_______________________________________________________________________\n"
"\n"
"${key:tickspersec}\n"
"TICKSPERSEC()\n"
"\n"
"Returns the number of ticks per second\n"
"_______________________________________________________________________\n"
"\n"
"${key:timer}\n"
"TIMER \n"
"\n"
"Returns the number of seconds from midnight\n"
"_______________________________________________________________________\n"
"\n"
"${key:time}\n"
"TIME\n"
"\n"
"Returns the current time as string \"HH:MM:SS\"\n"
"_______________________________________________________________________\n"
"\n"
"${key:timehms}\n"
"TIMEHMS hms | timer, @h, @m, @s\n"
"_______________________________________________________________________\n"
"\n"
"${key:date}\n"
"DATE \n"
"\n"
"Returns the current day as string \"DD/MM/YYYY\"\n"
"_______________________________________________________________________\n"
"\n"
"${key:julian}\n"
"JULIAN(dmy | (d,m,y))\n"
"\n"
"Returns the Julian date.\n"
"(dates must be greater than 1/1/100 AD)\n"
"\n"
"Example:\n"
"\n"
"PRINT Julian(DATE)\n"
"PRINT Julian(31, 12, 2001)\n"
"_______________________________________________________________________\n"
"\n"
"${key:datedmy}\n"
"DATEDMY dmy | julian_date, BYREF d, BYREF m, BYREF y\n"
"\n"
"Returns the day, month and the year as integers.\n"
"_______________________________________________________________________\n"
"\n"
"${key:weekday}\n"
"WEEKDAY(dmy | (d,m,y) | julian_date)\n"
"\n"
"Returns the day of the week (0 = Sunday)\n"
"\n"
"Example:\n"
"\n"
"PRINT WeekDay(DATE)\n"
"PRINT WeekDay(Julian(31, 12, 2001))\n"
"PRINT WeekDay(31, 12, 2001)\n"
"_______________________________________________________________________\n"
"\n"
"${key:datefmt}\n"
"DATEFMT(format, dmy | (d,m,y) | julian_date)\n"
"\n"
"Returns formated date string\n"
"\n"
"Format:\n"
"D = one or two digits of Day\n"
"DD = 2-digit day\n"
"DDD = 3-char day name\n"
"DDDD = full day name\n"
"M = 1 or 2 digits of month\n"
"MM = 2-digit month\n"
"MMM = 3-char month name\n"
"MMMM = full month name\n"
"YY = 2-digit year (2K)\n"
"YYYY = 4-digit year\n"
"\n"
"Example:\n"
"\n"
"PRINT DATEFMT(\"ddd dd, mm/yy\", \"23/11/2001\")\n"
"\n"
"REM prints \"Fri 23, 11/01\"\n"
"_______________________________________________________________________\n"
"\n"
"${key:delay}\n"
"DELAY ms\n"
"\n"
"Delay for a specified amount of milliseconds.\n"
"_______________________________________________________________________\n"
"\n"
"${key:sort}\n"
"SORT array [USE cmpfunc]\n"
"\n"
"Sorts an array.\n"
"\n"
"The cmpfunc (if its specified) it takes 2 vars to compare. \n"
"cmpfunc must returns\n"
"-1 if x < y\n"
"+1 if x > y\n"
" 0 if x = y\n"
"\n"
"Example:\n"
"\n"
"FUNC qscmp(x,y)\n"
"IF x=y \n"
"    qscmp=0\n"
"ELIF x>y\n"
"    qscmp=1\n"
"ELSE\n"
"    qscmp=-1\n"
"ENDIF\n"
"END\n"
"\n"
"DIM A(5)\n"
"FOR i=0 TO 5\n"
"    A(i)=RND\n"
"NEXT\n"
"SORT A USE qscmp(x,y)\n"
"_______________________________________________________________________\n"
"\n"
"${key:search}\n"
"SEARCH A, key, BYREF ridx [USE cmpfunc]\n"
"\n"
"Scans an array for the key.\n"
"If key is not found the SEARCH command returns (in ridx) the value \n"
"(LBOUND(A)-1). In default-base arrays that means -1.\n"
"\n"
"The cmpfunc (if its specified) it takes 2 vars to compare. \n"
"It must return 0 if x = y; non-zero if x <> y\n"
"\n"
"Example:\n"
"\n"
"FUNC cmp(x,y)\n"
"  cmp=!(x=y)\n"
"END\n"
"\n"
"DIM A(5)\n"
"FOR i=0 TO 5\n"
"    A(i)=5-i\n"
"NEXT\n"
"SEARCH A, 4, r USE cmp(x,y)\n"
"PRINT r:REM prints 1\n"
"PRINT A(r): REM prints 4\n"
"_______________________________________________________________________\n"
"\n"
"${key:chain}\n"
"CHAIN file\n"
"\n"
"Transfers control to another SmallBASIC program.\n"
"\n"
"file - A string expression that follows OS file naming conventions;\n"
"The file must be a SmallBASIC source code file.\n"
"\n"
"Example:\n"
"\n"
"CHAIN \"PROG2.BAS\"\n"
"_______________________________________________________________________\n"
"\n"
"${key:exec}\n"
"EXEC file\n"
"\n"
"Transfers control to another program\n"
"\n"
"This routine works like CHAIN with the exception the file can\n"
"be any executable file.\n"
"\n"
"EXEC never returns\n"
"_______________________________________________________________________\n"
"\n"
"${key:env}${key:environ}\n"
"ENVIRON \"expr\"\n"
"or\n"
"ENV \"expr\"\n"
"\n"
"Adds a variable to or deletes a variable from the current environment\n"
"variable-table.\n"
"\n"
"expr - A string expression of the form \"name=parameter\"\n"
"\n"
"If name already exists in the environment table, its current setting is\n"
"replaced with the new setting. If name does not exist, the new variable\n"
"is added.\n"
"\n"
"Notes: PalmOS: SB emulates environment variables\n"
"_______________________________________________________________________\n"
"\n"
"${key:env}${key:environ}\n"
"ENVIRON(\"var\")\n"
"or\n"
"ENV(\"var\")\n"
"\n"
"Returns the value of a specified entry in the current environment\n"
"table. If the parameter is empty (\"\") then returns an array of\n"
"the envirment variables (in var=value form)\n"
"\n"
"var  - A string expression of the form \"var\"\n"
"\n"
"Notes: PalmOS: SB emulates environment variables\n"
"_______________________________________________________________________\n"
"\n"
"${key:run}\n"
"RUN cmdstr\n"
"\n"
"Loads a secondary copy of system's shell and, executes an program, or \n"
"an shell command.\n"
"\n"
"cmdstr - Shell's specific command string\n"
"\n"
"After the specified shell command or program terminates, control is\n"
"returned to the line following the RUN command.\n"
"\n"
"Notes:\n"
"    * PalmOS: The 'cmdstr' is the Creator-ID\n"
"    * PalmOS: The RUN never returns\n"
"_______________________________________________________________________\n"
"\n"
"${key:run}\n"
"RUN(\"command\")\n"
"\n"
"RUN() is the function version of the RUN command. The difference is\n"
"that, the RUN() returns a string with the output of the 'command' as\n"
"an array of strings (each text-line is one element).\n"
"\n"
"Notes:\n"
"    * PalmOS: The RUN() does not supported.\n"
"    * Windows: The stdout and stderr are separated! First is the \n"
"      stdout output and following the stderr.\n"
"_______________________________________________________________________\n"
"\n"
"${key:tron}${key:troff}\n"
"TRON/TROFF\n"
"\n"
"TRACE ON/OFF. When trace mechanism is ON, the SB displays each line \n"
"number as the program is executed\n"
"_______________________________________________________________________\n"
"\n"
"${key:logprint}\n"
"LOGPRINT ...\n"
"\n"
"PRINT to SB's logfile. The syntax is the same with the PRINT command.\n"
"_______________________________________________________________________\n"
"\n"
"${key:malloc}${key:balloc}\n"
"MALLOC(size)\n"
"BALLOC(size)\n"
"\n"
"Allocates a memory block.\n"
"\n"
"Note: the variable can be freed by using ERASE\n"
"_______________________________________________________________________\n"
"\n"
"${key:vadr}\n"
"VADR(var)\n"
"\n"
"Returns the memory address of the variable's data.\n"
"_______________________________________________________________________\n"
"\n"
"${key:peek}${key:peek16}${key:peek32}\n"
"PEEK(addr)\n"
"PEEK16(addr)\n"
"PEEK32(addr)\n"
"\n"
"Returns the byte, word or dword at a specified memory address.\n"
"_______________________________________________________________________\n"
"\n"
"${key:poke}${key:poke16}${key:poke32}\n"
"POKE   addr, byte\n"
"POKE16 addr, word\n"
"POKE32 addr, dword\n"
"\n"
"Writes a specified byte, word or dword at a specified memory address.\n"
"_______________________________________________________________________\n"
"\n"
"${key:usrcall}\n"
"USRCALL addr\n"
"\n"
"Transfers control to an assembly language subroutine.\n"
"\n"
"The USRCALL is equal to:\n"
"\n"
"void (*f)(void);\n"
"f = (void (*)(void)) addr;\n"
"f();\n"
"_______________________________________________________________________\n"
"\n"
"${key:bcopy}\n"
"BCOPY src_addr, dst_addr, length\n"
"\n"
"Copies a memory block from 'src_addr' to 'dst_addr'\n"
"_______________________________________________________________________\n"
"\n"
"${key:bload}\n"
"BLOAD filename[, address]\n"
"\n"
"Loads a specified memory image file into memory.\n"
"_______________________________________________________________________\n"
"\n"
"${key:bsave}\n"
"BSAVE filename, address, length\n"
"\n"
"Copies a specified portion of memory to a specified file.\n"
"_______________________________________________________________________\n"
"\n"
"${key:stkdump}\n"
"STKDUMP\n"
"\n"
"Displays the SB's internal executor's stack\n"
"\n"
"_______________________________________________________________________\n"
"\n"
;