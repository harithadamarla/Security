#cat Random.txt
sed 's/\.//g;s/\(.*\)/\L\1/;s/\ /\n/g' test.txt | sort | uniq -c;
