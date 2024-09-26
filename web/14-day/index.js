var main = document.querySelector("#main");

function change() {
  if (main.style.backgroundColor === "red") {
    main.style.backgroundColor = "green";
  } else if (main.style.backgroundColor == "green") {
    main.style.backgroundColor = "black";
  } else {
    main.style.backgroundColor = "red";
  }
}
