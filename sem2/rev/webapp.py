from flask import Flask, render_template, request, redirect, url_for
from werkzeug.security import generate_password_hash, check_password_hash

app = Flask(__name__)
app.config['SECRET_KEY'] = 'your_secret_key'

users = []

class User:
    def __init__(self, username, password):
        self.username = username
        self.password = generate_password_hash(password)

class Product:
    def __init__(self, name, price):
        self.name = name
        self.price = price

    def __repr__(self):
        return f"{self.name} - {self.price}"

products = [
    Product("Medicine A", 30),
    Product("Medicine B", 20),
    Product("Medicine C", 10),
    Product("Medicine D", 40),
]

@app.route('/')
def home():
    return render_template('home.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        for user in users:
            if user.username == username and check_password_hash(user.password, password):
                return redirect(url_for('shop'))
        return redirect(url_for('login'))
    return render_template('login.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        user = User(username, password)
        users.append(user)
        return redirect(url_for('login'))
    return render_template('register.html')

@app.route('/shop')
def shop():
    return render_template('shop.html', products=products)

if __name__ == '__main__':
    app.run(debug=True)
