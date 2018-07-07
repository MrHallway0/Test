# $MidnightBSD$

echo 1..60

REGRESSION_START($1)

REGRESSION_TEST(`x', `jot -w "%X" -s , 100 1 200')
REGRESSION_TEST(`hhhh', `jot 50 20 120 2')
REGRESSION_TEST(`hhhd', `jot 50 20 120 -')
REGRESSION_TEST(`hhdh', `jot 50 20 - 2')
REGRESSION_TEST(`hhdd', `jot 50 20 - -')
REGRESSION_TEST(`hdhh', `jot 50 - 120 2')
REGRESSION_TEST(`hdhd', `jot 50 - 120 -')
REGRESSION_TEST(`hddh', `jot 50 - - 2')
REGRESSION_TEST(`hddd', `jot 50 - - -')
REGRESSION_TEST(`dhhh', `jot - 20 120 2')
REGRESSION_TEST(`dhhd', `jot - 20 120 -')
REGRESSION_TEST(`dhdh', `jot - 20 - 2')
REGRESSION_TEST(`dhdd', `jot - 20 - -')
REGRESSION_TEST(`ddhh', `jot - - 120 2')
REGRESSION_TEST(`ddhd', `jot - - 120 -')
REGRESSION_TEST(`dddh', `jot - - - 2')
REGRESSION_TEST(`dddd', `jot - - - -')
REGRESSION_TEST(`hhhh2', `jot 30 20 160 2')
REGRESSION_TEST(`hhhd2', `jot 30 20 160 -')
REGRESSION_TEST(`hhdh2', `jot 30 20 - 2')
REGRESSION_TEST(`hhdd2', `jot 30 20 - -')
REGRESSION_TEST(`hdhh2', `jot 30 - 160 2')
REGRESSION_TEST(`hdhd2', `jot 30 - 160 -')
REGRESSION_TEST(`hddh2', `jot 30 - - 2')
REGRESSION_TEST(`hddd2', `jot 30 - - -')
REGRESSION_TEST(`dhhh2', `jot - 20 160 2')
REGRESSION_TEST(`dhhd2', `jot - 20 160 -')
REGRESSION_TEST(`ddhh2', `jot - - 160 2')
REGRESSION_TEST(`rand1', `jot -r 10000 0 9 | sort -u')
REGRESSION_TEST(`rand2', `jot -r 10000 9 0 | sort -u')
REGRESSION_TEST(`n21', `jot 21 -1 1.00')
REGRESSION_TEST(`ascii', `jot -c 128 0')
REGRESSION_TEST(`xaa', `jot -w xa%c 26 a')
REGRESSION_TEST(`yes', `jot -b yes 10')
REGRESSION_TEST(`ed', `jot -w %ds/old/new/ 30 2 - 5')
REGRESSION_TEST(`stutter', `jot - 9 0 -.5')
REGRESSION_TEST(`stutter2', `jot -w %d - 9.5 0 -.5')
REGRESSION_TEST(`block', `jot -b x 512')
REGRESSION_TEST(`tabs', `jot -s, - 10 132 4')
REGRESSION_TEST(`grep', `jot -s "" -b . 80')
REGRESSION_TEST(`wf', `jot -w "a%.1fb" 10')
REGRESSION_TEST(`we', `jot -w "a%eb" 10')
REGRESSION_TEST(`wwe', `jot -w "a%-15eb" 10')
REGRESSION_TEST(`wg', `jot -w "a%20gb" 10')
REGRESSION_TEST(`wc', `jot -w "a%cb" 10 33 43')
REGRESSION_TEST(`wgd', `jot -w "a%gb" 10 .2')
REGRESSION_TEST(`wu', `jot -w "a%ub" 10')
REGRESSION_TEST(`wo', `jot -w "a%ob" 10')
REGRESSION_TEST(`wx', `jot -w "a%xb" 10')
REGRESSION_TEST(`wX1', `jot -w "a%Xb" 10')
REGRESSION_TEST(`wXl', `jot -w "a%Xb" 10 2147483648')
REGRESSION_TEST(`wdl', `jot -w "a%db" 10 2147483648 2>/dev/null')
REGRESSION_TEST(`wxn', `jot -w "a%xb" 10 -5 2>/dev/null')
REGRESSION_TEST(`wdn', `jot -w "a%db" 10 -5')
REGRESSION_TEST(`wp1', `jot -w "%%%d%%%%" 10')
REGRESSION_TEST(`wp2', `jot -w "%d%%d%%" 10')
REGRESSION_TEST(`wp3', `jot -w "a%%A%%%d%%B%%b" 10')
REGRESSION_TEST(`wp4', `jot -w "%%d%d%%d%%" 10')
REGRESSION_TEST(`wp5', `jot -w ftp://www.example.com/pub/uploaded%%20files/disk%03d.iso 10')
REGRESSION_TEST(`wp6', `jot -w "%d%" 10')

REGRESSION_END()
