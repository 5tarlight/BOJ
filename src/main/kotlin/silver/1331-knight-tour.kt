package silver

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun toInt(str: String): Int {
    return when (str) {
        "A" -> 1
        "B" -> 2
        "C" -> 3
        "D" -> 4
        "E" -> 5
        "F" -> 6
        else -> -1
    }
}

fun toPair(str: String): Pair<Int, Int> {
    return Pair(toInt(str.slice(0..0)), str.slice(1..1).toInt())
}

fun isInRange(p1: Pair<Int, Int>, p2: Pair<Int, Int>): Boolean {
    val x1 = p1.first
    val y1 = p1.second
    val x2 = p2.first
    val y2 = p2.second

    return abs(x1 - x2) == 1 && abs(y1 - y2) == 2
        || abs(x1 - x2) == 2 && abs(y1 - y2) == 1
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val set = mutableSetOf<String>()
    var start: Pair<Int, Int> = Pair(-1, -1)
    var prev: Pair<Int, Int> = Pair(-1, -1)
    var ok = true

    for (i in 1..36) {
        val line = br.readLine()

        if (set.contains(line)) {
            ok = false
            break
        }

        val current = toPair(line)

        if (i == 1) {
            start = current
        } else {
            if (!isInRange(prev, current)) {
                ok = false
                break
            }

            if (i == 36) {
                if (!isInRange(current, start)) {
                    ok = false
                    break
                }
            }
        }

        set.add(line)
        prev = current
    }

    println(if (ok) "Valid" else "Invalid")
}
