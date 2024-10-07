const URL = 'data.json';

const fetchData = async () => {
	try {
		const response = await fetch(URL);
		const data = await response.json();
		console.log('Fetched Data:', data);

		data.students.forEach(student => {
			console.log(`Student ID: ${student.id}, Name: ${student.name}`);
		});

		return data; // Return the data for further processing
	} catch (error) {
		console.log('Error fetching data:', error);
	}
};

const appendStudent = async (newStudent) => {
	const data = await fetchData();
	if (!data) return; // Ensure data is fetched before appending

	data.students.push(newStudent); // Append the new student
	console.log('Updated Student List:', data.students);

	// Here you would typically send the updated data back to the server or save it
	// For example, you might use fetch to send a POST request to save the updated data
	// await fetch(URL, { method: 'POST', body: JSON.stringify(data), headers: { 'Content-Type': 'application/json' } });
};

// Example usage
const newStudent = { id: 4, name: 'John Doe' };
appendStudent(newStudent);
