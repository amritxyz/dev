// let a = prompt("Enter a number");

// switch (a) {
// 	case "1":
// 		alert("You entered number: " + a);
// 		break;
// 	case "2":
// 		alert("You entered number: 2");
// 		break;
// 	case "3":
// 		alert("You entered number: 3");
// 		break;
// 	default:
// 		alert("Default");
// }

// function calculate() {
//     const num1 = parseFloat(prompt("Enter the first number:"));
//     const operator = prompt("Enter the operator (+, -, *, /):");
//     const num2 = parseFloat(prompt("Enter the second number:"));

//     let result;

//     switch (operator) {
//         case '+':
//             result = num1 + num2;
//             break;
//         case '-':
//             result = num1 - num2;
//             break;
//         case '*':
//             result = num1 * num2;
//             break;
//         case '/':
//             if (num2 === 0) {
//                 result = "Can't divide by zero";
//             } else {
//                 result = num1 / num2;
//             }
//             break;
//         default:
//             result = 'Invalid operator';
//             break;
//     }

//     alert('Result: ' + result);
// }

// calculate();

// let day = new Date().getDay();
// let result;
//      switch (day) {
//          case 0:
//              result = "Sunday";
//              break;
//          case 1:
//              result = "Monday";
//              break;
//          case 2:
//              result = "Tuesday";
//              break;
//          case 3:
//              result = "Wednesday";
//              break;
//          case 4:
//              result = "Thursday";
//              break;
//          case 5:
//              result = "Friday";
//              break;
//          case 6:
//              result = "Saturday";
//              break;
//          default:
//              result = 'Invalid operator';
//              break;
//      }
// (result);

// function myFunction() {
	// let num1 = prompt("Enter first no: ");
	// let num2 = prompt("Enter second no: ");
	// console.log(parseInt(num1) + parseInt(num2));
// }
// myFunction();

// Function with no parameters and no return type
// function abc() {
// 	console.log("Hello");
// }
// abc();

// // Function with no parameter & no return
// funtion bcd(a,b) {
// 	console.log(a + b);
// }

// // Function with no parameter but return
// bcd(5, 4);
// 	funtion cde() {
// 		let a = 4;
// 		let b = 6
// 		return a + b;
// 	}

// For loop in JavaScript

// console.log("Hello, World!");
// for(let i=0; i<5; i++){
// 	console.log("Hello, World!");
// }

// let a = ["a", "b", "c", "d", "e"]
// for (i = 0; i < a.length; i++)
// 	console.log(a[i]);

// let obj = {name:"Hari",address:"Butwal"};

// for (item in obj)
// 	console.log(obj[item]);


// let language = "JavaScript";

// let text = "";
// for (let x of language) {
//   text += x + "\n";
// }
// console.log(text);

// const cars = ["BMW", "Volvo", "Mini"];

// let text = "";
// for (let x of cars) {
//   text += x + "\n";
// }
// console.log(text);

let a = [
	"a",
	"b",
	"c",
	"d",
	"e",
	"f",
	"g",
	"h"];
let search = prompt("Enter the alphabet you want to search: ");
let found = false;

for (let i=0; i<a.length; i++){
	if (a[i] == search){
		alert("The alphabet is found");
		console.log("The index is " +i);
		found = true;
		break;
	}

	if (!found){
		alert("The alphabet is not found");
		break;
	}
}
console.log("The index is " +i);
