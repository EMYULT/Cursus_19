#!/bin/bash
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White
i=1
y=0

rm -rf ~/Desktop/test_result/*.txt
#test1
TEST="'ls'"
A=$(ls > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
    #echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test2
TEST="-l"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test3
TEST="-la"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi


#test4
TEST="-lar"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi


#test5
TEST="-lart"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test6
TEST="-lartR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi


#test7
TEST="-lr"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test8
TEST="-lrt"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test10
TEST="-lrtR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test11
TEST="-lt"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test12
TEST="-ltR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test13
TEST="-lR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test14
TEST="-a"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test15
TEST="-ar"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test16
TEST="-art"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test17
TEST="-artR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi


#test18
TEST="-at"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test19
TEST="-atr"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test20
TEST="-aR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi


#test21
TEST="-r"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test22
TEST="-rt"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test23
TEST="-rtR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test24
TEST="-rR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test25
TEST="-t"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test26
TEST="-tR"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test27
TEST="-R"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test28
TEST="-y"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test29
TEST="-a -a"
let "i++"
A=$(ls -1 $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST ../../../ > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi

#test30
TEST="-l"
let "i++"
A=$(ls -1 $TEST /dev > /Users/hde-ghel/Desktop/test_result/${i}_ls.txt 2>&1)
B=$(./ft_ls $TEST /dev > /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt 2>&1)
DIFF=$(diff /Users/hde-ghel/Desktop/test_result/${i}_ls.txt /Users/hde-ghel/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "$Red TEST ${i} '$TEST' FAIL !$Color_Off"
#echo "diff |$DIFF{}|"
else
    echo "$Green TEST ${i} '$TEST' OK !$Color_Off"
fi
exit 0
