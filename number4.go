package main

import("fmt")

    func input(row *[] int, numbers *int, amt *int) bool {
    _, err : = fmt.Scan(numbers) if err != nil { return false }
    if !(*numbers <= 50000 && *numbers >= 5) {
        return false
    }
    _, err = fmt.Scan(amt) if err != nil { return false }
    if !(*amt >= 2 && *amt <= 100) {
        return false
    }
        for
        i:
            = 0;
        i < *numbers;
        i++ { var number int fmt.Scan(&number) *row = append(*row, number) }
        return true
}

func min(a, b int) int {
    if a
        > b { return b }
    return a
}

func game(row[] int, numbers int, amt int) int {
i:= 0
	player := 0
	ban := 0
	score0, score1 := 0, 0
	choice0, choice1 := 0, 0

	for i < numbers {
    maxAmt:
        = min(amt, numbers - i) idealSum : = 0 idealAmt : = -1 if player == 0 { ban = choice0 } else {
			ban = choice1
		}
		sum := 0
		for j := 1;
        j <= maxAmt;
        j++ {
            sum += row[i + j - 1] if j == ban { continue }
            if idealAmt
                == -1 { idealAmt = j idealSum = sum }
            else if sum
                > idealSum { idealSum = sum idealAmt = j }
            else if sum
                == idealSum &&idealAmt > j { idealAmt = j }
        }
        if idealAmt
            == -1 { idealAmt = 1 idealSum += row[i] }
        if player
            == 0 { score0 += idealSum choice0 = idealAmt }
        else {
            score1 += idealSum choice1 = idealAmt
        }
        player = 1 - player i += idealAmt
    }
    if score0
        > score1 { return 1 }
    return 0
}

func main() {
    var row[] int var numbers, amt int if input (&row, &numbers, &amt) {
        fmt.Println(game(row, numbers, amt))
    }
    else {
        fmt.Println("Последовательность от 5 до 50000, ход от 2 до 100")
    }
}
