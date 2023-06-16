package silver

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()

    for (i in 1..n) {
        val str = br.readLine()
        var ok = true
        var num = 0

        for (c in str.toCharArray()) {
            if (c == '(')
                num++
            else {
                num--
                if (num < 0) {
                    ok = false
                    break
                }
            }
        }

        if (ok && num == 0)
            println("YES")
        else
            println("NO")
    }
}
