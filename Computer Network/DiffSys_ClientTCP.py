import socket
def tcp_client(port):
    host = input("Enter the server IP address: ")
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))
    print(f"Connected to server: {host}:{port}")
    while True:
        message = input("Client: ")
        client_socket.sendall(message.encode())
        response = client_socket.recv(1024).decode()
        if not response:
            print("Server has disconnected.")
            break
        print(f"Server: {response}")
    client_socket.close()
port = int(input("Enter the port number: "))
tcp_client(port)