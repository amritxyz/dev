fn is_prime(n: u32) -> bool {
    if n <= 1 {
        return false; // Numbers less than or equal to 1 are not prime
    }
    for i in 2..=(n as f64).sqrt() as u32 {
        if n % i == 0 {
            return false; // n is divisible by i, so it's not prime
        }
    }
    true // n is prime
}

fn main() {
    let n = 29; // Example number to check
    if is_prime(n) {
        println!("{} is prime", n);
    } else {
        println!("{} is not prime", n);
    }
}
