import socket
def tcp_server(port):
    host = ''
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)
    print(f"TCP server is listening on port {port}")
    client_socket, client_address = server_socket.accept()
    print(f"Connected to client: {client_address}")
    while True:
        data = client_socket.recv(1024).decode()
        if not data:
            print("Client has disconnected.")
            break
        print(f"Client: {data}")
        response = input("Server: ")
        client_socket.sendall(response.encode())
    client_socket.close()
    server_socket.close()
port = int(input("Enter the port number: "))
tcp_server(port)