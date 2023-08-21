use std::io;

fn read_num() -> i32 {
    let mut num = String::new();
    io::stdin().read_line(&mut num).unwrap();

    num.trim().parse().unwrap()
}

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
    read_num();
    let a = read_nums();
    read_num();
    let b = read_nums();

    let mut results = Vec::with_capacity(b.len());

    for t in b.iter() {
        let count = a.iter()
            .filter(|&v| v == t)
            .collect::<Vec<_>>()
            .len();

        results.push(count);
    }

    let str = results
        .iter()
        .map(|&v| format!("{}", v))
        .collect::<Vec<_>>()
        .join(" ");
    println!("{str}")
}
