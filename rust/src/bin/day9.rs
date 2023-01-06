use std::{fs, time::Instant};
#[derive(Copy, Clone, PartialEq, Debug)]
struct Point {
    x: i32, y: i32,
}

fn abs(x: i32) -> i32 {
    if x < 0 {
        return -1 * x;
    }
    return x;
}

fn is_touching(p1: Point, p2: Point) -> bool {
    if abs(p1.x - p2.x) <= 1 && abs(p1.y - p2.y) <=1 {
        return true;
    }
    return false;
}

fn move_tail(head: Point, tail: Point) -> Point {
    // let points: Vec<Point> = vec![
        // Point{x: head.x-1, y: head.y},
        // Point{x: head.x+1, y: head.y},
        // Point{x: head.x, y: head.y-1},
        // Point{x: head.x, y: head.y+1},
    // ];

    // for point in points {
        // if is_touching(point, tail) {
            // return point;
        // }
    // }
}

fn move_head(line: &str, _head: Point) -> Point {
    let mut head = _head;
    if line.chars().nth(0) == Some('R') {
        head.x = _head.x + 1;
    } else if line.chars().nth(0) == Some('L') {
        head.x = _head.x - 1;
    } else if line.chars().nth(0) == Some('U') {
        head.y = _head.y + 1;
    } else if line.chars().nth(0) == Some('D') {
        head.y = _head.y - 1;
    }

    return head;
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
        Point{x: 0, y: 0},
    ];
    visited_points.push(tails[9]);

    contents
        .strip_suffix("\n")
        .unwrap()
        .split("\n")
        .into_iter()
        .for_each(|line| {
            let mag = line[2..line.len()].parse::<i32>().unwrap();

            for _ in 0..mag {
                head = move_head(line, head);
                if is_touching(head, tails[0]) { continue; }
                tails[0] = move_tail(head, tails[0]);

                for i in 1..tails.len() {
                    if !is_touching(tails[i-1], tails[i]) {
                        tails[i] = move_tail(tails[i-1], tails[i]);
                    }
                }

                if !visited_points.contains(&tails[9]) {
                    visited_points.push(tails[9]);
                }
            }
        });

    // 2608 too small
    println!("Answer: {}", visited_points.len());
    println!("Time elapsed {}", start.elapsed().as_millis());
}
