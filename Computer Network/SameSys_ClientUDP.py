import socket
ip_address = input("Enter IP address: ")
port = int(input("Enter port number: "))
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
while True:
    message = input("Enter your message: ")
    client_socket.sendto(message.encode(), (ip_address, port))
    if message.lower() == "bye":
        print("Closing the connection.")
        break
    response, server_address = client_socket.recvfrom(1024)
    response = response.decode()
    print(f"Server response: {response}")
client_socket.close()