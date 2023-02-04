#!/bin/bash
rm ./numbersFile.txt

DIR=./in
if [ ! -d "$DIR" ];
then
    mkdir ./in
fi

DIR=./out
if [ ! -d "$DIR" ];
then
    mkdir ./out
fi

echo "How much test do you want?"
read tests
echo "$tests" > ./numbersFile.txt

echo "Give size for all arrays"
read size

for (( i=1; i<=$tests; i++ ))
do
    echo "$size $i" >> ./input.txt
    echo "$i" >> ./numbersFile.txt
done

for (( i=1; i<=$tests; i++ ))
do
    cat ./input.txt | head -1 | cut -d" " -f1 > ./in/test$i.in
   ./generareTeste < ./input.txt >> ./in/test$i.in
   touch ./out/test$i.out
   sed -i '1d' ./input.txt
done

touch ./out/verifyResult.txt

rm ./input.txt

