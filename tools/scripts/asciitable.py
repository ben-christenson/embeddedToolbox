#!/usr/bin/python

def printtable():
   for x in range(256):
      print x, hex(x), unichr(x)


if __name__ == "__main__":
    printtable()

