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
    let nums = read_num();
    let mut words: Vec<String> = vec![];

    for _ in 0..nums {
        let mut str = String::new();
        io::stdin().read_line(&mut str).unwrap();
        str = String::from(str.trim());

        words.push(str);
    }

    words.sort_by(|a, b| {
        if a.len() == b.len() {
            a.cmp(b)
        } else {
            a.len().cmp(&b.len())
        }
    });

    words.dedup();

    for word in words {
        println!("{}", word);
    }
}
