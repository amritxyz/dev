var select = document.querySelector(".toggle-bar");
var change = document.querySelector("body");

function toggle() {
  if (select.style.left == "54%") {
    select.style.left = "1%";
    change.style.backgroundColor = "white";
    change.style.transition = "0.5s";
  } else {
    select.style.left = "54%";
    change.style.backgroundColor = "black";
    change.style.transition = "0.5s";
  }
}
