package silver

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Deque
import java.util.LinkedList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val sb = StringBuilder()
    val lineNum = br.readLine().toInt()
    val queue: Deque<Int> = LinkedList()
    val lines = mutableListOf<String>()

    for (i in 1..lineNum)
        lines.add(br.readLine())

    for (l in lines) {
        val line = l.split(" ")
        val op = line[0]

        when (op) {
            "push" -> queue.add(line[1].toInt())
            "pop" -> sb.append(queue.poll() ?: -1).append("\n")
            "size" -> sb.append(queue.size).append("\n")
            "empty" -> sb.append(if (queue.isEmpty()) 1 else 0).append("\n")
            "front" -> {
                if (queue.isEmpty())
                    sb.append(-1).append("\n")
                else
                    sb.append(queue.first()).append("\n")
            }
            "back" -> {
                if (queue.isEmpty())
                    sb.append(-1).append("\n")
                else
                    sb.append(queue.last()).append("\n")
            }
        }
    }

    println(sb.toString())
}
