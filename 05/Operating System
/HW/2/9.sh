#!/bin/bash

# Function to execute a command
execute_command() {
  eval "$1"
}

# Function to execute a piped command
execute_piped_command() {
  eval "$1 | $2"
}

# Function to redirect output of a command to a file
redirect_output_to_file() {
  eval "$1 > $2"
}

# Main script logic
echo "Choose an option:"
echo "1. Execute a command"
echo "2. Execute a piped command"
echo "3. Redirect output of a command to a file"
read -p "Enter your choice: " choice

case $choice in
1)
  read -p "Enter the command to execute: " cmd
  execute_command "$cmd"
  ;;
2)
  read -p "Enter the first command: " cmd1
  read -p "Enter the second command: " cmd2
  execute_piped_command "$cmd1" "$cmd2"
  ;;
3)
  read -p "Enter the command: " cmd
  read -p "Enter the file name: " file
  redirect_output_to_file "$cmd" "$file"
  ;;
*)
  echo "Invalid choice"
  ;;
esac
