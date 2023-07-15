import socket
def udp_server(port):
    host = ''  
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind((host, port))
    print(f"UDP server is listening on port {port}")
    while True:
        data, client_address = server_socket.recvfrom(1024)
        print(f"Received data from {client_address}: {data.decode()}")
        response = input("Server: ")
        server_socket.sendto(response.encode(), client_address)
        if not data:
            print("Client disconnected.")
            break
    server_socket.close()
port = int(input("Enter the port number: "))
udp_server(port)