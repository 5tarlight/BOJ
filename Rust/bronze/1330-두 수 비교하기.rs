use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let input: Vec<i32> = input
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let a = input[0];
    let b = input[1];

    if a > b {
        println!(">");
    } else if a < b {
        println!("<");
    } else {
        println!("==")
    }
}
