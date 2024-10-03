#!/bin/sh

#printf "Your Name: "
#read name
#printf "\n"

# Check if the input is empty
if [ -z "$name" ]; then
    name="$USER"
fi
printf "> Hello, $name!\n"

# Get the current hour (24-hour format)
hour=$(date +%H)

# Determine the greeting based on the hour
if [ "$hour" -lt 12 ]; then
    echo "> Good morning!"
elif [ "$hour" -lt 18 ]; then
    echo "> Good afternoon!"
else
    echo "> Good evening!"
fi

echo "> You spent $hour hr of a day."

echo "> Its $(date +'%I:%M:%S %p')."
printf "\n"

# Calendar
cal

#string="Hello"
#printf "$string $USER ! \n\n"
