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
    let mut str = String::new();
    io::stdin().read_line(&mut str).unwrap();
    str = String::from(str.trim());

    let mut results = vec![];

    for i in 1..str.len() - 1 {
        for j in (i + 1)..str.len() {
            let a = &str[..i];
            let b = &str[i..j];
            let c = &str[j..];

            let mut result = String::from("");
            result.push_str(&a.chars().rev().collect::<String>());
            result.push_str(&b.chars().rev().collect::<String>());
            result.push_str(&c.chars().rev().collect::<String>());

            results.push(result);
        }
    }

    results.sort();
    println!("{}", results.first().unwrap());
}
