// BOJ Runtime Error
// Shit...

use std::io;

fn main() {
    let mut a = String::new();
    let mut b = String::new();

    io::stdin().read_line(&mut a).unwrap();
    io::stdin().read_line(&mut b).unwrap();

    let a: i32 = a.trim().parse().unwrap();
    let b: i32 = b.trim().parse().unwrap();

    println!("{}", a + b);
    println!("{}", a - b);
    println!("{}", a * b);
}
