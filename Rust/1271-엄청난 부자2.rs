// This code can't be compiled in BOJ
// Bug?

use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let input: Vec<i32> = input
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let rest = input[0] % input[1];
    println!("{}", (input[0] - rest) / input[1]);
    println!("{}", rest);
}
