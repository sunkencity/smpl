
This is a quick and dirty program to sample a percentage of random lines from stdin or a number of files

You can compile it with "make smpl".

Usage:

USER (~/programming/c/smpl)
$ ./smpl %1 /usr/share/dict/words | head
abidal
abidance
abler
abnormalness
abortifacient
absciss
absolutely
acanonical
acanthad
acanthocephalous

Also reads from stdin:

$ cat /usr/share/dict/words | ./smpl %1 | head
abacinate
abasia
abetment
abiogenetical
abiotrophy
abjurement
abstemious
Acaena
acceptor
accusably

Since it doesn't count the number of lines percentage is only approximate:

$ wc -l /usr/share/dict/words 
  235886 /usr/share/dict/words

$ ./smpl %1 /usr/share/dict/words | wc -l
    2350

$ ruby -e "puts 2350 / 235886.0"
0.009962439483479307

$ ./smpl %1 /usr/share/dict/words | wc -l
    2384

$ ruby -e "puts 2384 / 235886.0"
0.010106576905793476


