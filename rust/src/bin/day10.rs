use std::{fs, time::Instant, sync:: Mutex, collections::VecDeque};

#[allow(non_snake_case)]
fn main() {
    // part 1
    let start = Instant::now();
    let contents = fs::read_to_string("../10.in")
        .expect("Error reading file");
    
    {
        let mut x = 1;
        let mut cycle = 1;
        let mut total = 0;
        
        contents
            .strip_suffix("\n")
            .unwrap()
            .split("\n")
            .map(|line| line
                .split(' ')
                .collect::<Vec<&str>>())
            .for_each(|v| {
                if cycle % 40 == 20 {
                    total += cycle * x;
                }
                cycle += 1;

                if let Some(&"addx") = v.get(0) {
                    if cycle % 40 == 20 {
                        total += cycle * x;
                    }
                    let num = v.get(1).unwrap().parse::<i32>().unwrap();
                    x += num;
                    cycle += 1;
                }

            });
        println!("{}", total);
        println!("Time elapsed {}", start.elapsed().as_micros());
    }

    // part 2
    {
        const COLS: usize = 40;
        const ROWS: usize = 6;
        const SPRITE_WIDTH: i32 = 3;

        let mut x: i32 = 1;
        let mut cycle = 1;
        let mut screen = [' '; ROWS*COLS];

        let get_pixel = |c: usize, _x: i32| {
            let col = (c - 1) % COLS;
            if (_x-(col as i32)).abs() <= SPRITE_WIDTH / 2 {
                return '#'
            }
            return ' ';
        };

        contents
            .strip_suffix("\n")
            .unwrap()
            .split("\n")
            .map(|line| line
                .split(' ')
                .collect::<Vec<&str>>())
            .for_each(|v| {
                screen[cycle-1] = get_pixel(cycle, x);
                cycle += 1;
                if let Some(&"addx") = v.get(0) {
                    screen[cycle-1] = get_pixel(cycle, x);
                    x += v.get(1).unwrap().parse::<i32>().unwrap();
                    cycle += 1;
                }

            });

        let image = screen
            .chunks(COLS)
            .map(|row| row.iter().collect())
            .collect::<Vec<String>>()
            .join("\n");

        println!("{}", image);
    }
}
