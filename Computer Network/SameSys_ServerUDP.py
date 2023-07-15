import socket
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((ip_address, port))
print("UDP server is ready to receive messages.")
while True:
    data, client_address = server_socket.recvfrom(1024)
    data = data.decode()
    if not data:
        print("Client disconnected.")
        break
    print(f"Received message: {data}")
    response = input("Enter your response: ")
    server_socket.sendto(response.encode(), client_address)
server_socket.close()