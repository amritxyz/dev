use std::io::{self, Write};

fn main() {
    print!("Enter a string: ");
    io::stdout().flush().unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    input = input.trim().to_string();

    let reversed: String = input.chars().rev().collect();

    println!("Reversed string: {}", reversed);
}
