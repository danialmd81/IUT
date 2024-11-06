#! /bin/bash

arg_num=$#
arg_value=("$@")

echo -e "\n"
echo script $0 is runnig!
echo -e "\n"

echo -------------------------------------------
echo What are the odd numbered script arguments?
echo -------------------------------------------

# We can use a C like for loop!

for ((i=0;i<arg_num;i+=2));
do
  echo ${arg_value[${i}]}
done

#########################################

echo -----------------------------------------------------
echo Checking a condition. Is there a file named text.txt?
echo -----------------------------------------------------

if [ -e text.txt ]; then
  echo File is here!
else
  echo No such file or directory.
fi

########################################

echo --------------------------------------
echo Does \'new jersey\' precedes \'new york\'?
echo --------------------------------------

T1="new jersey"
T2="new york"

if [[ $T1 < $T2 ]]; then
  echo expression evaluated as true
else
  echo expression evaluated as false
fi

echo But only in words!

#########################################

echo ---------------------------------
echo How to run a command iteratively?
echo ---------------------------------

number_list=`seq 1 10`
for i in $number_list; do
  echo "Welcome $i times!"
done

echo ---------------------------------
echo Can we do it for a list of files?
echo ---------------------------------

for i in $(ls); do
  echo item: $i
done

#########################################

echo ---------------------------------------
echo But what if we want to keep iterating only \"WHILE\" some condition holds? 
echo E.g. while counter is single digit
echo ---------------------------------------

COUNTER=0
while [ $COUNTER -lt 10 ]; do
  echo The counter is single digit: $COUNTER
  let COUNTER=COUNTER+1
done

#########################################

echo --------------------------------
echo Or \"UNTIL\" the condition is met? 
echo --------------------------------

COUNTER=20
until [ $COUNTER -lt 10 ]; do
  echo The counter is $COUNTER 
  let COUNTER-=1
done

#########################################


