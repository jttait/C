# -*- Makefile -*-

clean:
	rm -rf *.o 120_test 120_run

101: 101.c
	gcc 101.c -o 101 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

102: 102.c
	gcc 102.c -o 102 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

103: 103.c
	gcc 103.c -o 103 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

104: 104.c
	gcc 104.c -o 104 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

105: 105.c
	gcc 105.c -o 105 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

106: 106.c
	gcc 106.c -o 106 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

107: 107.c
	gcc 107.c -o 107 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

108: 108.c
	gcc 108.c -o 108 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

109: 109.c
	gcc 109.c -o 109 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

110: 110.c
	gcc 110.c -o 110 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

111: 111.c
	gcc 111.c -o 111 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

112: 112.c
	gcc 112.c -o 112 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

113: 113.c
	gcc 113.c -o 113 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

114: 114.c
	gcc 114.c -o 114 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

115: 115.c
	gcc 115.c -o 115 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

116: 116.c
	gcc 116.c -o 116 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

117: 117.c
	gcc 117.c -o 117 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

118: 118.c
	gcc 118.c -o 118 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

119: 119.c
	gcc 119.c -o 119 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

120.o: 120.c
	gcc -c 120.c -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

120_run: 120_run.c 120.o
	gcc -o 120_run 120_run.c 120.o -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

120_test: 120_test.c 120.o
	gcc -o 120_test 120_test.c 120.o -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

121: 121.c
	gcc 121.c -o 121 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

122: 122.c
	gcc 122.c -o 122 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

123: 123.c
	gcc 123.c -o 123 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

124: 124.c
	gcc 124.c -o 124 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

201: 201.c
	gcc 201.c -o 201 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

202: 202.c
	gcc 202.c -o 202 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

203: 203.c
	gcc 203.c -o 203 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

204: 204.c
	gcc 204.c -o 204 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

205: 205.c
	gcc 205.c -o 205 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

206: 206.c
	gcc 206.c -o 206 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

207: 207.c
	gcc 207.c -o 207 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

208: 208.c
	gcc 208.c -o 208 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

209: 209.c
	gcc 209.c -o 209 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

210: 210.c
	gcc 210.c -o 210 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

301: 301.c
	gcc 301.c -o 301 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

302: 302.c
	gcc 302.c -o 302 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

303: 303.c
	gcc 303.c -o 303 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

304: 304.c
	gcc 304.c -o 304 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

305: 305.c
	gcc 305.c -o 305 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

306: 306.c
	gcc 306.c -o 306 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

401: 401.c
	gcc 401.c -o 401 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2

402: 402.c
	gcc 402.c -o 402 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

403: 403.c
	gcc 403.c -o 403 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

404: 404.c
	gcc 404.c -o 404 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

405: 405.c
	gcc 405.c -o 405 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

406: 406.c
	gcc 406.c -o 406 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

407: 407.c
	gcc 407.c -o 407 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

408: 408.c
	gcc 408.c -o 408 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

409: 409.c
	gcc 409.c -o 409 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm

410: 410.c
	gcc 410.c -o 410 -pedantic -ansi -Wall -Wextra -Wfloat-equal -O2 -lm
