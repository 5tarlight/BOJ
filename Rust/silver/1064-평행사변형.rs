// Suck!

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

fn minus(a: (i32, i32), b: (i32, i32)) -> (i32, i32) {
    (a.0 - b.0, a.1 - b.1)
}

fn plus(a: (i32, i32), b: (i32, i32)) -> (i32, i32) {
    (a.0 + b.0, a.1 + b.1)
}

fn div(a: i32, b: i32) -> f64 {
    if b == 0 {
        -1.0
    } else {
        a as f64 / b as f64
    }
}

fn dis(a: (i32, i32), b: (i32, i32)) -> f64 {
    let da = (a.0 - b.0) as f64;
    let db = (a.1 - b.1) as f64;

    (da * da + db * db).sqrt()
}

fn main() {
    let nums = read_nums();
    let a = (nums[0], nums[1]);
    let b = (nums[2], nums[3]);
    let c = (nums[4], nums[5]);

    let ab = minus(a, b);
    let bc = minus(b, c);
    let ca = minus(c, a);

    let dab = div(ab.0, ab.1);
    let dbc = div(bc.0, bc.1);
    let dca = div(ca.0, ca.1);

    if dab == dbc && dbc == dca {
        println!("-1.0");
        return;
    }

    // c-a-b
    let d1 = plus(c, ab);
    let d2 = plus(b, ca);
    let d3 = plus(a, bc);

    let len1 = dis(a, b) + dis(b, c) + dis(c, d1) + dis(d1, a);
    let len2 = dis(a, b) + dis(b, d2) + dis(d2, c) + dis(c, a);
    let len3 = dis(a, d3) + dis(b, d3) + dis(b, c) + dis(c, a);

    let gap = (len1.max(len2.max(len3)) - len1.min(len2.min(len3))).abs();

    if gap == gap.round() {
        println!("{:}.0", gap);
    } else {
        println!("{:.}", gap);
    }
}
