var select = document.querySelector(".toggle-bar");
var container = document.querySelector("#toggle-container");
var change = document.querySelector("body");
var nav = document.querySelector("nav");

function toggle() {
  if (select.style.left == "54%") {
    select.style.left = "1%";
    select.style.backgroundColor = "white";
    select.style.border = "2px solid black";
    change.style.backgroundColor = "white";
    change.style.color = "black";
    change.style.transition = "0.5s";
    nav.style.backgroundColor = "green";
    nav.style.transition = "0.7s";
    container.style.border = "2px solid black";
    container.style.backgroundColor = "black";
  } else {
    select.style.left = "54%";
    select.style.backgroundColor = "black";
    select.style.border = "2px solid white";
    change.style.backgroundColor = "black";
    change.style.color = "white";
    change.style.transition = "0.5s";
    nav.style.backgroundColor = "blue";
    nav.style.transition = "0.7s";
    container.style.border = "2px solid white";
    container.style.backgroundColor = "white";
  }
}
