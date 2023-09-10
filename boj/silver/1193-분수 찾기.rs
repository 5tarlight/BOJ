use std::io;

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

    let mut line = 1;
    let mut sum = 1;

    while sum < num {
        line += 1;
        sum = line * (line + 1) / 2;
    }
    line -= 1;
    sum = line * (line + 1) / 2;

    let a;
    let b;
    if line % 2 == 0 {
        b = num - sum;
        a = line + 2 - b;
    } else {
        a = num - sum;
        b = line + 2 - a;
    }

    println!("{a}/{b}");
}
