from flask import Flask, render_template, jsonify, Response
from tcp_receiver import start_tcp_server
from log_buffer import buffer

app = Flask(__name__)

@app.route('/')
def index() -> str:
    return render_template('index.html')

@app.route('/state')
def state() -> Response:
    return jsonify(buffer.get_state())

@app.route('/tile/<int:x>/<int:y>')
def tile(x: int, y: int) -> str:
    return render_template('tile.html', x=x, y=y, players=buffer.get_tile(x, y))

if __name__ == '__main__':
    start_tcp_server()
    app.run(use_reloader=False)
