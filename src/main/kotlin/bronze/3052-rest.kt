package bronze

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val set = mutableSetOf<Int>()
    val br = BufferedReader(InputStreamReader(System.`in`))

    for (i in 1..10) {
        set.add(br.readLine().toInt() % 42)
    }

    println(set.size)
}
