from .AgenticIntelligenceKpiWorkflow import Freakster, Status
from .Communication import createSocket, SocketReceiveError
from select import poll, POLLIN
import socket as skt
import threading


def mainLoop(machine, port, name):
    Exit = True
    firstConnection = Freakster(0, 0, createSocket(machine, port, name))
    family = {firstConnection.socket.fileno(): firstConnection}
    pollObject = poll()
    pollObject.register(firstConnection.socket, POLLIN)

    while Exit:
        pollEvent = pollObject.poll(0)

        for socketfd, event in pollEvent:
            if (event & POLLIN):
                ai = family[socketfd]
                if ai.handshake == False and ai.welcome == False:
                    try:
                        ai.firstHandshake(name)
                    except SocketReceiveError:
                        Exit = False
                elif ai.handshake == False and ai.welcome == True:
                    try:
                        res = ai.finalHandshake()
                        if res == True:
                            newAi = Freakster(0, 0, createSocket(machine, port, name))
                            family.update({newAi.socket.fileno(): newAi})
                            pollObject.register(newAi.socket, POLLIN)
                        ai.startThread()
                    except SocketReceiveError:
                        Exit = False
                else:
                    try:
                        s = ai.receive()
                        ai.received = s
                        ai.threadEvent.set()
                        print(f"s = {s}")
                    except SocketReceiveError:
                        Exit = False

        if len(family) == 0:
            break

    print("out")
    for t in family.values():
        print("family")
        t.socket.close()
        t.thread.join()
    print("End of the program.")
