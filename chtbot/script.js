const responses = {
    "hi":"Hello! Welcome to our restaurant.",
    "hello":"Hi! How can I help you?",
    "menu":"We have Biryani, Paneer, Dosa and Butter Chicken.",
    "biryani":"Chicken and Veg Biryani available.",
    "dosa":"Masala and Plain dosa available.",
    "paneer":"Paneer Butter Masala is popular.",
    "dessert":"We serve Gulab Jamun and Rasmalai.",
    "delivery":"Yes we provide home delivery.",
    "timing":"Open from 10 AM to 11 PM.",
    "location":"We are on MG Road Pune.",
    "price":"Prices start from Rs.120.",
    "bye":"Goodbye! Visit again."
};

function send() {
    let chat = document.getElementById("chat");
    let input = document.getElementById("input").value.toLowerCase();

    chat.innerHTML += "<p><b>You:</b> " + input + "</p>";

    let result = "Sorry, I didn't understand that.";

    for (let key in responses) {
        if (input.includes(key)) {
            result = responses[key];
            break;
        }
    }

    chat.innerHTML += "<p><b>Bot:</b> " + result + "</p>";

    document.getElementById("input").value = "";
    chat.scrollTop = chat.scrollHeight;
}
