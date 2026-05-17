package main

import(
    "fmt"
    "math")

    func input(first, second *int) bool {
    _, err : = fmt.Scan(first, second) if err != nil { return false }
    return *first > 0 && *first < 11 && *second > 0 && *second < 11
}

func gcd(idealNum, idealDen int64) int64 {
        for
            idealDen != 0 { idealNum %= idealDen idealNum, idealDen = idealDen, idealNum }
        return idealNum
}

func row(first, second int) int {
    if second == 1 {
		fmt.Println("infinity")
		return 0
	}

	var sum float64 = 0.0
	for n := 1;
    n < 200; n++ {
		sum += math.Pow(float64(n), float64(first)) / math.Pow(float64(second), float64(n))
	}

	var idealNum, idealDen int64 = 0, 1
	idealError := 1e14

	for den := int64(1);
    den < 10000;
    den++ {
    num:
        = int64(math.Round(sum * float64(den))) err
            : = math.Abs(sum - float64(num) / float64(den)) if err < idealError {
            idealError = err idealNum = num idealDen = den
        }
    }

div:
    = gcd(idealNum, idealDen) fmt.Printf("%d/%d\n", idealNum / div, idealDen / div) return 0
}

func main() {
    var first, second int if input (&first, &second) { row(first, second) }
    else {
        fmt.Println("Введите корректные значения")
    }
}
