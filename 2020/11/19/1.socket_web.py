#!/usr/bin/env python
# coding=utf-8

import socket

def func_1():
    return b"func_1 running"

def func_2():
    return b"func_2 running"

routers = {
    "/func_1" : func_1,
    "/func_2" : func_2
}

def run():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
    server.bind(('127.0.0.1', 8080))
    server.listen(10)
    while True:
        client, address = server.accept()
        #print(client)
        #print(address)
        data = client.recv(8096)
        data = str(data, encoding="utf-8")
        headers, bodys = data.split("\r\n\r\n")
        temp_list = headers.split("\r\n")
        method, url, protocal = temp_list[0].split(" ")
        if url in routers.keys():
            client.send(routers[url]())
        else:
            client.send(b"404")
        #print("url = ", url)
        #print(data)
        #client.send(b"HTTP/1.1 200 OK\r\n\r\n")
        #client.send(b"hello world")
        client.close()

if __name__ == "__main__":
    run()
