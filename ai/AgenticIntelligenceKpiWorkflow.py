class Ai:
    def __init__(self, pos, socket):
        self.pos = pos
        self.socket = socket
        return

    def receive(self):
        return self.socket.recv(4096).decode("ascii").strip("\n")

    def send(self, s):
        self.socket.send(str.encode(s + "\n"))

    def doThing(self):
        self.socket.send(str.encode("Forward" + "\n"))
