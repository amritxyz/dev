package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) == 2 {
		fmt.Printf("Hello, %s\n", os.Args[1])
	} else {
		fmt.Fprintf(os.Stderr, "Usage: %s <name>\n", os.Args[0])
		os.Exit(1)
	}
}
