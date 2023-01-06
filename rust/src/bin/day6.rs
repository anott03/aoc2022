use std::{fs, time::Instant};

fn main() {
    let start = Instant::now();

    let contents = fs::read_to_string("../6.in")
        .expect("Error reading file");

    let part = 4;

    let mut first: bool = true;
    contents
        .strip_suffix("\n")
        .unwrap()
        .chars()
        .into_iter()
        .enumerate()
        .for_each(|(i, _c)| {
            if i > part-1 && first {
                let substr = &contents.as_str()[i-part..i];
                let res: usize = substr
                    .chars()
                    .into_iter()
                    .map(|char| substr.matches(char).count())
                    .collect::<Vec<usize>>()
                    .iter()
                    .sum();
                if res == part {
                    first = false;
                    println!("Answer: {}", i);
                }
            }
        });

    println!("Time elapsed {}", start.elapsed().as_micros());
}
