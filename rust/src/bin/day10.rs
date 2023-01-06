use std::{fs, time::Instant, sync::{Arc, Mutex}, collections::VecDeque};

#[allow(non_snake_case)]
fn main() {
    let start = Instant::now();
    let contents = fs::read_to_string("../10.ex")
        .expect("Error reading file");
    
    let cycle = Arc::new(Mutex::new(0));
    let X = Arc::new(Mutex::new(1));
    let mut total = 0;
    let active_job = Arc::new(Mutex::new(false));

    let jobs: Arc<Mutex<VecDeque<(i32, i32)>>> = Arc::new(Mutex::new(VecDeque::new()));

    let mut tick = || {
        let mut locked_cycle = cycle.lock().unwrap();
        *locked_cycle += 1;
        let mut locked_jobs = jobs.lock().unwrap();
        let mut locked_X = X.lock().unwrap();
        if vec![20, 60, 100, 140, 180, 220].contains(&locked_cycle) {
            total += *locked_cycle * *locked_X;
            println!("{} {} {}", locked_cycle, locked_X, total);
            // std::process::exit(1);
        }
        match locked_jobs.get(0) {
            Some(job) => {
                if *locked_cycle == job.1 {
                    *locked_X += job.0;
                    // println!("{}: adding {}", *locked_cycle, job.0);
                    locked_jobs.pop_front();
                    let mut active_job = active_job.lock().unwrap();
                    *active_job = false;
                    drop(active_job);
                }
            },
            None => {}
        }
        drop(locked_jobs);
        drop(locked_X);
        drop(locked_cycle);
    };

    contents
        .strip_suffix("\n")
        .unwrap()
        .split("\n")
        .into_iter()
        .map(|line| line
            .split(' ')
            .collect::<Vec<&str>>())
        .for_each(|v| {
            if let Some(&"noop") = v.get(0) {
                tick();
            } else if let Some(&"addx") = v.get(0) {
                let mut locked_active_job = active_job.lock().unwrap();
                // println!("{:?}", v);
                while *locked_active_job {
                    drop(locked_active_job);
                    tick();
                    locked_active_job = active_job.lock().unwrap();
                }
                let mut locked_jobs = jobs.lock().unwrap();
                let locked_X = X.lock().unwrap();
                let locked_cycle = cycle.lock().unwrap();
                locked_jobs.push_back((
                    v.get(1).unwrap().parse::<i32>().unwrap(),
                    *locked_cycle+2
                ));
                *locked_active_job = true;
                drop(locked_active_job);
                drop(locked_cycle);
                drop(locked_jobs);
                drop(locked_X);
                tick();
            }
        });

    let mut locked_jobs = jobs.lock().unwrap();
    while locked_jobs.len() > 0 {
        drop(locked_jobs);
        tick();
        locked_jobs = jobs.lock().unwrap();
    }
    drop(locked_jobs);

    let locked_X = X.lock().unwrap();
    let locked_cycle = cycle.lock().unwrap();

    // 97920, 18360 -> too high
    println!("Answer: {}", total);
    println!("Time elapsed {}", start.elapsed().as_millis());
    drop(locked_X);
    drop(locked_cycle);
}
