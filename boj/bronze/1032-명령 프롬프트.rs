use std::io;

fn main() {
    let mut len = String::new();
    io::stdin().read_line(&mut len).unwrap();
    let len: usize = len.trim().parse().unwrap();

    let mut names: Vec<String> = vec![];

    for _ in 0..len {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let input = input.trim();

        names.push(String::from(input));
    }

    let mut result = String::new();
    let len = names[0].len();

    for i in 0..len {
        let target = names[0].chars().nth(i).unwrap();
        let mut filter = false;

        for s in &names {
            if s.chars().nth(i).unwrap() != target {
                filter = true;
            }
        }

        if filter {
            result.push('?');
        } else {
            result.push(target);
        }
    }

    println!("{}", result);
}
