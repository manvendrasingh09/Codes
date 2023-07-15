import socket
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((ip_address, port))
server_socket.listen(1)
print("TCP server is ready to receive messages.")
client_socket, client_address = server_socket.accept()
print(f"Connected to client: {client_address}")
while True:
    data = client_socket.recv(1024).decode()
    if not data:
        print("Client disconnected.")
        break
    print(f"Received message: {data}")
    response = input("Enter your response: ")
    client_socket.send(response.encode())
client_socket.close()
server_socket.close()