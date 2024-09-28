var nav = document.querySelector("#nav");
var bar = document.querySelector(".toggle-bar");
var container = document.querySelector("#toggle-container");

function toggle() {
	if (bar.style.left == "54%") {
		bar.style.left = "1%";
		bar.style.backgroundColor = "white";
	} else {
		bar.style.left = "54%";
		container.style.backgroundColor = "white";
		bar.style.backgroundColor = "black";
	}
}
