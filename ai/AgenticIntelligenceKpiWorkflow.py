from .Communication import SocketReceiveError

class Freakster:
    def __init__(self, pos, socket):
        self.pos = pos
        self.socket = socket
        self.welcome = False
        self.handshake = False

    def firstHandshake(self, name):
        s = self.receive()
        if s == "WELCOME":
            self.send(name)
            self.welcome = True

    def finalHandshake(self):
        s = self.receive()
        try:
            arr = [int(tmp) for tmp in s.split()]
        except ValueError:
            return
        if len(arr) != 3:
            return
        self.pos = (arr[1], arr[2])
        self.handshake = True
        if arr[0] > 0:
            return True
        return False


    def receive(self):
        s = self.socket.recv(4096)
        if s == b'':
            raise SocketReceiveError("Server has stopped.")
        return s.decode("ascii").strip("\n")

    def send(self, s):
        self.socket.send(str.encode(s + "\n"))

    def doThing(self):
        self.socket.send(str.encode("Forward" + "\n"))
