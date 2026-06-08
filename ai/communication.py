from .client import Client
from os import fork
import socket as skt

def mainLoop(machine, port, name):
    mainSocket = skt.socket(skt.AF_INET, skt.SOCK_STREAM)
    mainSocket.setsockopt(skt.SOL_SOCKET, skt.SO_REUSEADDR, 1)
    try:
        mainSocket.connect((machine, port))
    except ConnectionRefusedError:
        print("The Client cannot connect to the server. It's either due to a wrong ip, a wrong port, or the server being closed.")
        exit(84)

    while True:
        s = mainSocket.recv(4096)
        if s == b'':
            print("Server has stopped. Exiting Program")
            exit(0)

        s = s.decode("ascii").strip('\n')

        if (s == "WELCOME"):
            mainSocket.send(str.encode(name + "\n"))
            a = mainSocket.recv(4096).decode("ascii").strip('\n')
            if a != 'ko':
                id = fork()
                if id == 0:
                    break

    gameSocket = skt.socket(skt.AF_INET, skt.SOCK_STREAM)
    gameSocket.setsockopt(skt.SOL_SOCKET, skt.SO_REUSEADDR, 1)
    try:
        gameSocket.connect((machine, port))
    except ConnectionRefusedError:
        print("Can't connect the IA")
    print("IA Connected")
    # a = 0
