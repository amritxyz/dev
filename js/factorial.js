const readline = require('readline');

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

function factorial(n) {
	if (n < 0) return "Factorial is not defined for negative numbers";
	if (n === 0) return 1; // Base case: factorial of 0 is 1
	let result = 1;
	for (let i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

rl.question('Enter a number: ', (answer) => {
	const number = parseInt(answer, 10);
	if (isNaN(number)) {
		console.log("Please enter a valid number");
	} else {
		console.log(`Factorial of ${number} is ${factorial(number)}`);
	}
	rl.close();
});
