import java.util.Scanner;
public class IPaddress {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("ip address: ");
        String ip_21BCE0201 = scanner.nextLine();
        System.out.print("Enter Number of subnets: ");
        int sub_21BCE0201 = scanner.nextInt();
        scanner.close();
        System.out.println("Manvendra Singh 21BCE0201");
        String[] ipParts_21BCE0201 = ip_21BCE0201.split("\\.");
        int first = Integer.parseInt(ipParts_21BCE0201[0]);
        int len = ipParts_21BCE0201.length;
        int flag = 0;
        for (int i = 0; i < len; i++) {
            if (ipParts_21BCE0201[i].contains("/")) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            classful(ipParts_21BCE0201, sub_21BCE0201, first);
        else
            classless(ip_21BCE0201, sub_21BCE0201);
    }
    private static void classful(String[] ipParts_21BCE0201, int sub_21BCE0201, int first) {
        String ip_21BCE0201 = String.join(".", ipParts_21BCE0201);
        System.out.println(ip_21BCE0201 + " is a classful format of ");
        char classIp;
        if (first < 128) {
            classIp = 'A';
            System.out.println("Class: " + classIp);
        } else if (first < 192) {
            classIp = 'B';
            System.out.println("Class: " + classIp);
        } else if (first < 224) {
            classIp = 'C';
            System.out.println("Class: " + classIp);
        } else if (first < 240) {
            classIp = 'D';
            System.out.println("Class: " + classIp);
        } else if (first < 256) {
            classIp = 'E';
            System.out.println("Class: " + classIp);
        } else {
            System.out.println("Invalid IP");
            return;
        }

        int[] A = new int[4];
        int j = 0;
        String buffer = "";
        for (int i = 0; i < ip_21BCE0201.length(); i++) {
            if (ip_21BCE0201.charAt(i) == '.') {
                A[j] = Integer.parseInt(buffer);
                buffer = "";
                j++;
            } else {
                buffer += ip_21BCE0201.charAt(i);
            }
        }
        A[3] = 0;
        if (sub_21BCE0201 % 2 == 0) {
            for (int i = 0; i < sub_21BCE0201; i++) {
                System.out.println((i + 1) + " Subnet:");
                System.out.print("ip address of the subnet: ");
                long totalHosts;
                if (classIp == 'A') {
                    totalHosts = (long) Math.pow(2, 24);
                    System.out.println(A[0] + ".0.0.0");
                    System.out.println("Total number of IP Addresses: " + 256 / sub_21BCE0201);
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / sub_21BCE0201 - 2));
                } else if (classIp == 'B') {
                    totalHosts = (long) Math.pow(2, 16);
                    System.out.println(A[0] + "." + A[1] + ".0.0");
                    System.out.println("Total number of IP Addresses: " + 256 / sub_21BCE0201);
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / sub_21BCE0201 - 2));
                } else if (classIp == 'C') {
                    totalHosts = (long) Math.pow(2, 8);
                    System.out.println(A[0] + "." + A[1] + "." + A[2] + "." + A[3]);
                    System.out.println("Total number of IP Addresses: " + 256 / sub_21BCE0201);
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / sub_21BCE0201 - 2));
                    System.out.println("Range of IP Addresses:");
                    System.out.println("St IP: " + A[0] + "." + A[1] + "." + A[2] + "." + A[3]);
                    System.out.println("End IP: " + A[0] + "." + A[1] + "." + A[2] + "." + (A[3] + 256 / sub_21BCE0201 - 1));
                    System.out.println("Direct Broadcast Address: " + A[0] + "." + A[1] + "." + A[2] + "." + (A[3] + 256 / sub_21BCE0201 - 1));
                    A[3] += 256 / sub_21BCE0201;
                } else {
                    totalHosts = (long) Math.pow(2, 0);
                    System.out.println(A[0] + "." + A[1] + "." + A[2] + "." + A[3]);
                    System.out.println("Total number of IP Addresses: " + 256 / sub_21BCE0201);
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / sub_21BCE0201 - 2));
                }
                System.out.println("Limited Broadcast Address: 255.255.255.255");
            }
        } else {
            int k = -1;
            for (int i = 0; i < sub_21BCE0201; i++) {
                System.out.println((i + 1) + " Subnet:");
                System.out.print("ip address of the subnet: ");
                long totalHosts;
                if (classIp == 'A') {
                    totalHosts = (long) Math.pow(2, 24);
                    System.out.println(A[0] + ".0.0.0");
                    System.out.println("Total number of IP Addresses: " + 256 / sub_21BCE0201);
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / sub_21BCE0201 - 2));
                } else if (classIp == 'B') {
                    totalHosts = (long) Math.pow(2, 16);
                    System.out.println(A[0] + "." + A[1] + ".0.0");
                    System.out.println("Total number of IP Addresses: " + 256 / sub_21BCE0201);
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / sub_21BCE0201 - 2));
                } else if (classIp == 'C') {
                    totalHosts = (long) Math.pow(2, 8);
                    System.out.println(A[0] + "." + A[1] + "." + A[2] + "." + A[3]);
                    System.out.println("Total number of IP Addresses: " + 256 / (sub_21BCE0201 + k));
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / (sub_21BCE0201 + k) - 2));
                    System.out.println("Range of IP Addresses:");
                    System.out.println("St IP: " + A[0] + "." + A[1] + "." + A[2] + "." + A[3]);
                    System.out.println("End IP: " +A[0] + "." + A[1] + "." + A[2] + "." + (A[3] + 256 / (sub_21BCE0201 + k) - 1));
                    System.out.println("Direct Broadcast Address: " + A[0] + "." + A[1] + "." + A[2] + "." + (A[3] + 256 / (sub_21BCE0201 + k) - 1));
                    A[3] += 256 / (sub_21BCE0201 + k);
                    k = 1;
                } else {
                    totalHosts = (long) Math.pow(2, 0);
                    System.out.println(A[0] + "." + A[1] + "." + A[2] + "." + A[3]);
                    System.out.println("Total number of IP Addresses: " + 256 / sub_21BCE0201);
                    System.out.println("Total number of hosts that can be configured: " + (totalHosts / sub_21BCE0201 - 2));
                }
                System.out.println("Limited Broadcast Address: 255.255.255.255");
            }
        }
    }
    private static void classless(String ip_21BCE0201, int sub_21BCE0201) {
        System.out.println(ip_21BCE0201 + " is a classless format");
    }
}