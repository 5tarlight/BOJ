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
    let mut tests: Vec<String> = vec![];

    for _ in 0..num {
        let mut str = String::new();
        io::stdin().read_line(&mut str).unwrap();
        str = String::from(str.trim());
        tests.push(str);
    }

    let mut result = 0;

    for word in tests {
        let chars = word.chars().collect::<Vec<char>>();
        let mut prev = chars[0];
        let mut history = vec![prev];
        let mut valid = true;

        let chars = chars[1..].to_vec();

        for ch in chars {
            if ch == prev {
                continue;
            } else {
                if history.contains(&ch) {
                    valid = false;
                    break;
                } else {
                    prev = ch;
                    history.push(ch);
                }
            }
        }

        if valid {
            result += 1;
        }
    }

    println!("{}", result);
}
