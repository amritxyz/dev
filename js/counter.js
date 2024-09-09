function makeCounter() {
	let count = 0;
	return function() {
		count++;
		return count;
	};
}
const counter = makeCounter();
console.log(counter()); // 1
console.log(counter()); // 2
