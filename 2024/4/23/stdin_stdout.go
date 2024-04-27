package main

import (
	"os"
	"fmt"
	"bufio"
)


func main() {
	var n int
	fmt.Scanf("%d", &n)
	fmt.Println(n)
	for i := 1; i <= n; i++ {
		var s string
		fmt.Scanf("%s", &s)
		fmt.Println(s)
	}
	reader := bufio.NewReader(os.Stdin)
	for i := 1; i <= n; i++ {
		s, err := reader.ReadString('\n')
		s = s[:len(s) - 1]
		fmt.Println(len(s))
		fmt.Println(s)
		if err != nil {
			return 
		}
		// reader.Text()
	}
	// for i := 1; i <= n; i++ {
	// 	var s string
	// 	fmt.Scanln(&s)
	// 	fmt.Println(s)
	// }
	// for i := 1; i <= n; i++ {
	// 	var s string
	// 	fmt.Scanln("%s\n", &s)
	// 	fmt.Println(s)
	// }
}