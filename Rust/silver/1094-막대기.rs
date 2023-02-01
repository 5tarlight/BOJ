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
    let len = read_num();
    let mut my = vec![64];

    loop {
        let sum: i32 = my.iter().sum();
        if sum == len {
            break;
        }

        my.sort_by(|a, b| b.partial_cmp(a).unwrap());
        let shortest = my.pop().unwrap() / 2;
        let halfsum: i32 = my.iter().sum();

        if halfsum + shortest >= len {
            my.push(shortest);
        } else {
            my.push(shortest);
            my.push(shortest);
        }
    }

    println!("{}", my.len());
}
