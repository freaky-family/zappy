import socket
import threading
import datetime
from log_buffer import buffer

def handle_client(conn):
    with conn:
        data = ""
        while True:
            chunk = conn.recv(4096).decode("utf-8", errors="replace")
            if not chunk:
                break
            data += chunk
            while "\n" in data:
                line, data = data.split("\n", 1)
                line = line.strip()
                if line:
                    buffer.append({
                        "timestamp": datetime.datetime.now().isoformat(timespec="seconds"),
                        "message": line,
                    })

def start_tcp_server(host="0.0.0.0", port=4343):
    def _run():
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as srv:
            srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            srv.bind((host, port))
            srv.listen(5)
            while True:
                conn, _ = srv.accept()
                threading.Thread(target=handle_client, args=(conn,), daemon=True).start()
    threading.Thread(target=_run, daemon=True).start()
