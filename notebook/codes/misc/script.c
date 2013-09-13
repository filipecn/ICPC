while :
do
./gen > input
./debug < input > a
./brute < input > b

result=$(diff -u a b)

if [ $? -eq 0 ]; then
    date
else
    echo "Found it!"
    exit 1
fi

sleep 0.01

done

