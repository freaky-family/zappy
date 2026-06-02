from .communication import hello
from .utils import print_help

import sys

def main():
    argv = sys.argv[1:]
    argc = len(argv)

    if (argc == 1 and argv[0] == "--help"):
        return print_help()
    if (not(argc == 4 or argc == 6)):
        exit(84)

    port: int
    name: str
    machine: str = "localhost"
    try:
        while (len(argv) > 0):
            match argv[0]:
                case "-p":
                    port = int(argv[1])
                case "-n":
                    name = argv[1]
                case "-h":
                    machine = argv[1]
            argv = argv[2:]
    except:
        exit(84)
    hello()

if __name__ == "__main__":
    main()
