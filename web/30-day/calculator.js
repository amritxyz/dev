// calculator.js


let display = document.getElementById('display');

let operator = '';

let num1 = '';

let num2 = '';


function clearDisplay() {

    display.value = '';

    operator = '';

    num1 = '';

    num2 = '';

}


function backspace() {

    display.value = display.value.slice(0, -1);

}


function appendNumber(num) {

    display.value += num;

}


function appendOperator(op) {

    operator = op;

    num1 = display.value;

    display.value = '';

}


function calculate() {

    num2 = display.value;

    let result;


    switch (operator) {

        case '+':

            result = parseFloat(num1) + parseFloat(num2);

            break;

        case '-':

            result = parseFloat(num1) - parseFloat(num2);

            break;

        case '*':

            result = parseFloat(num1) * parseFloat(num2);

            break;

        case '/':

            result = parseFloat(num1) / parseFloat(num2);

            break;

        default:

            result = 'Error';

    }


    display.value = result;

}
