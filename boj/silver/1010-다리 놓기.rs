use std::{io, vec};

#[allow(dead_code)]
fn read_num() -> i32 {
    let mut num = String::new();
    io::stdin().read_line(&mut num).unwrap();

    num.trim().parse().unwrap()
}

#[allow(dead_code)]
fn read_nums() -> Vec<i32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    input
        .as_mut_str()
        .split_whitespace()
        .map(|v| v.trim().parse().unwrap())
        .collect()
}

fn main() {
    let num = read_num();
    let mut list: Vec<(i32, i32)> = vec![];

    for _ in 0..num {
        let inputs = read_nums();
        list.push((inputs[0], inputs[1]));
    }

    let mut result: f64;
    for (a, b) in list {
        result = 1.0;

        for i in 0..a {
            result *= (b - i) as f64;
            result /= (i + 1) as f64;
        }

        println!("{}", result);
    }
}
