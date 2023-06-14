package silver

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.round

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val nums = mutableListOf<Int>()

    for (i in 1..n) {
        nums.add(br.readLine().toInt())
    }

    val groups = nums.groupBy { it }
        .entries
        .sortedByDescending { (k, v) -> v.size }
    val msvs = groups
        .filter { (k, v) -> v.size == groups.first().value.size }
        .sortedBy { (k, v) -> k }
    val msv = if (msvs.size > 1) {
        msvs[1].key
    } else
        msvs[0].key

    println(round(nums.sum().toDouble() / n.toDouble()).toInt())
    println(nums.sorted()[(n - 1) / 2])
    println(msv)
    print(nums.max() - nums.min())
}
