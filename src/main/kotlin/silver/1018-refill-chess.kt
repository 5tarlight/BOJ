package silver

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val nms = br.readLine().split(" ")
    val n = nms[0].toInt()
    val m = nms[1].toInt()

    val board = mutableListOf<List<Char>>()

    for (i in 1..n) {
        board.add(br.readLine().toList())
    }

    val set = mutableSetOf<Int>()

    for (xOffset in 0..n - 8) {
        for (yOffset in 0..m - 8) {
            var start = '1'
            var correction = 0

            for (x in 0..7) {
                for (y in 0..7) {
                    val X = xOffset + x
                    val Y = yOffset + y

                    if (x == 0 && y == 0)
                        start = board[X][Y]
                    else if (abs(x - y) % 2 == 0) {
                        if (start != board[X][Y])
                            correction++
                    } else {
                        if (start == board[X][Y])
                            correction++
                    }
                }
            }

            set.add(correction)

            start = if (start == 'B') 'W' else 'B'
            correction = 0

            for (x in 0..7) {
                for (y in 0..7) {
                    val X = xOffset + x
                    val Y = yOffset + y

                    if (abs(x - y) % 2 == 0) {
                        if (start != board[X][Y])
                            correction++
                    } else {
                        if (start == board[X][Y])
                            correction++
                    }
                }
            }

            set.add(correction)
        }
    }

    println(set.min())
}
