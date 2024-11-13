use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() == 2 {
        println!("Hello, {}", args[1]);
    }
    else {
        eprintln!("Usage: {} <name>", args[0]);
        process::exit(1);
    }
}
