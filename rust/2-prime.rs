fn is_prime(n: u32) -> bool {
    if n <= 1 {
        return false;
    }
    for i in 2..=(n as f64).sqrt() as u32 {
        if n % i == 0 {
            return false;
        }
    }
    true // Prime
}

fn main() {
    let n = 29;
    if is_prime(n) {
        println!("{} is prime", n);
    } else {
        println!("{} is not prime", n);
    }
}
