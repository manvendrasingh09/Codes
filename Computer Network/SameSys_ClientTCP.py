import socket
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((ip_address, port))
print("Connected to server.")
while True:
    message = input("Enter your message: ")
    client_socket.send(message.encode())
    if message.lower() == "bye":
        print("Closing the connection.")
        break
    response = client_socket.recv(1024).decode()
    print(f"Server response: {response}")
client_socket.close()