use std::{fs, time::Instant};

#[derive(Copy, Clone, PartialEq, Debug)]
struct Point {
    x: i32, y: i32,
}

fn is_touching(p1: Point, p2: Point) -> bool {
    if (p1.x - p2.x).abs() <= 1 && (p1.y - p2.y).abs() <=1 {
        return true;
    }
    return false;
}

fn main() {
    let start = Instant::now();

    let contents = fs::read_to_string("../9.in")
        .expect("Error reading file");

    let mut visited_points: Vec<Point> = Vec::new();
    let mut head = Point { x: 0, y: 0 };
    let mut tails = [
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
        Point{x: 0, y: 0},
    ];
    let tail = &mut tails[0];
    visited_points.push(Point { x: 0, y: 0 });

    contents
        .strip_suffix("\n")
        .unwrap()
        .split("\n")
        .for_each(|line| {
            let mag = line[2..line.len()].parse::<i32>().unwrap();
            let dir = &line[0..1];

            for _ in 0..mag {
                match dir {
                    "U" => head.y += 1,
                    "D" => head.y -= 1,
                    "L" => head.x -= 1,
                    "R" => head.x += 1,
                    &_ => {}
                }

                let dx = head.x - tail.x;
                let dy = head.y - tail.y;
                if !is_touching(head, *tail) {
                    tail.x += dx.signum();
                    tail.y += dy.signum();

                    if !visited_points.contains(tail) {
                        visited_points.push(Point{ x: tail.x, y: tail.y });
                    }
                }
            }
        });

    // 2608 too small
    // visited_points.iter().for_each(|point| println!("{:?}", point));
    println!("Answer: {}", visited_points.len());
    println!("Time elapsed {}", start.elapsed().as_millis());
}
