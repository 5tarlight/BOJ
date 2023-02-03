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

    let mut results: Vec<String> = vec![];

    for str in tests {
        let mut cp = str.clone();
        let mut finish = false;

        while cp.len() > 0 {
            println!("Iter : {cp}");
            if cp.starts_with("100") {
                cp.remove(0);
                cp.remove(0);
                cp.remove(0);

                while cp.starts_with("0") {
                    cp.remove(0);
                }

                if !cp.starts_with("1") {
                    finish = true;
                    results.push(String::from("NO"));
                    break;
                }

                cp.remove(0);
                while cp.starts_with("1") {
                    cp.remove(0);
                }
            } else if cp.starts_with("01") {
                cp.remove(0);
                cp.remove(0);
            } else {
                results.push(String::from("NO"));
                finish = true;
                break;
            }
        }

        if !finish {
            results.push(String::from("YES"));
        }
    }

    for result in results {
        println!("{result}");
    }
}
