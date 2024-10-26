let currentInput = "";
let operation = null;
let firstOperand = null;

function addToDisplay(value) {
	const display = document.getElementById("display");
	currentInput += value;
	display.value = currentInput;
}

function setOperation(op) {
	if (currentInput === "") return;
	if (firstOperand === null) {
		firstOperand = parseFloat(currentInput);
	} else if (operation) {
		firstOperand = operate(operation, firstOperand, parseFloat(currentInput));
	}
	operation = op;
	currentInput = "";
}

function operate(op, a, b) {
	switch (op) {
		case "+":
			return a + b;
		case "-":
			return a - b;
		case "*":
			return a * b;
		case "/":
			return a / b;
		default:
			return b;
	}
}

function calculate() {
	if (currentInput === "" || operation === null) return;
	const display = document.getElementById("display");
	const result = operate(operation, firstOperand, parseFloat(currentInput));
	display.value = result;
	currentInput = "";
	firstOperand = result;
	operation = null;
}

function clearOne() {
	const display = document.getElementById("display");
	currentInput = currentInput.slice(0, -1);
	// display.value = currentInput;
	display.value = display.value.slice(0, -1);
}

function clearAll() {
	const display = document.getElementById("display");
	currentInput = "";
	firstOperand = null;
	operation = null;
	display.value = "";
}
