var hell = document.querySelector("h1");

hell.style.color = "red";
hell.innerHTML = "hello bro whats up!";
hell.addEventListener("mouseover", function () {
  hell.style.color = "green";
});
hell.addEventListener("mouseout", function () {
  hell.style.color = "red";
});

const name = "Amrit";
const age = 18;
console.log(`My name is ${name} and i am ${age} years old.`);
