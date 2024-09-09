// Using Promises
function fetchData() {
	return new Promise((resolve, reject) => {
		setTimeout(() => resolve("Data fetched"), 1000);
	});
}
fetchData().then(data => console.log(data));

// Using Async/Await
async function fetchDataAsync() {
	const data = await fetchData();
	console.log(data);
}
fetchDataAsync();
