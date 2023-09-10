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
    let num = read_num() as i128;
    let faces = read_nums();

    let mut sorted = faces.clone();
    sorted.sort();

    if num == 1 {
        let result = faces.iter().sum::<i32>() - sorted[5];
        println!("{}", result);
        return;
    }

    let center: i128 = (num - 2) * (num - 2) * 5 + (num - 2) * 4;
    let edge = (num - 2) * 8 + 4;
    let vertex = 4i128;

    // 0 - 5, 1 - 4, 2 - 3
    let mut two = sorted[0] as i128 + sorted[1] as i128;

    let least_index = faces.iter().position(|&x| x == sorted[0]).unwrap();
    let second_index = faces.iter().position(|&x| x == sorted[1]).unwrap();

    if least_index + second_index == 5 {
        two = sorted[0] as i128 + sorted[2] as i128;
    }

    let three = sorted[0].min(sorted[5]) + sorted[1].min(sorted[4]) + sorted[2].min(sorted[3]);

    let result: i128 = center * sorted[0] as i128 + edge * two + vertex * three as i128;

    println!("{}", result);
}
