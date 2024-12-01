use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();

    match args.len() {
    2 => {
        println!("Hello, {}", args[1]);
        process::exit(0);
    }
    _ => {
        println!("Usage: {} <name>", args[0]);
        println!("Please provide exactly one argument for the name");
        process::exit(1);
    },
    }
}
