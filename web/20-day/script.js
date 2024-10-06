///////////////////////////////////////////

let arr1 = [1, 2, 3]
let arr2 = [4, 5, 6]

arr3 = [ ...arr1, arr2]
console.log(arr3);
///////////////////////////////////////////

const myFunction = (...a
{
sum = 0;
for (item 0f a)
{
sum += item;
}
console.log(sum);
}
myFunction(1,2,3,4,5,6,7,8,9);
///////////////////////////////////////////


let obj = {
fname: "john",
age: 25,
}

console.log(obj);


////////////////////////////////////////

// 2 inouts address, college using prompt and assign to object
let address = prompt("enter your address:")
let college = prompt("enter your college name:")
let info = {
address,
college,
};

console.log(info);
/////////////////////////////////////////////

// promises

let myPromise = newPromise( { resolve, reject } =>
	{
		resolve( "Success" );
	} )
myPromise.then( ( data ) =>
	{
		console.log( data );
	}).catch( ( error ) =>
		{
			console.log(error);
		} )
