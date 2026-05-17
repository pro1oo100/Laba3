package main

import(
    "fmt"
    "math")

    func input(xMin, xMax, step *float64) bool {
    var n int _, err : = fmt.Scan(xMin, xMax, step) if err != nil{return false} n = 3 if n == 3 && *step > 0 {
        return true
    }
    return false
}

func function(xMin, xMax, step float64) {
        var y float64
	fmt.Printf("%5s%20s\n", "X", "Y")
	fmt.Println("-------------------------------") // 31 дефис
	for xMin <= xMax {
            if xMin
                < -2 { y = -0.5 * xMin - 1.5 }
            if xMin
                >= -2 && xMin <= 2 { y = 2 * math.Cos(2 * xMin) }
            if xMin
                > 2 {y = 0.5 * xMin - 1.5} fmt.Printf("%9.4f%20.4f\n", xMin, y) xMin += step
        }
        fmt.Println("-------------------------------")
}

func main() {
    var xMin, xMax, step float64 if input (&xMin, &xMax, &step) { function(xMin, xMax, step) }
    else {
        fmt.Println("Введите корректные значения")
    }
}
