import java.util.Scanner;
public class classless {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String ipDecStr = scanner.nextLine();
        scanner.close();
        String[] ipDecArr = ipDecStr.split("\\.|/");
        int resbitnet_21BCE0201 = Integer.parseInt(ipDecArr[4]);
        int resbithost_21BCE0201 = 32 - resbitnet_21BCE0201;
        int thost_21BCE0201 = (int) Math.pow(2, resbithost_21BCE0201);
        String H0S_21BCE0201 = new String(new char[resbithost_21BCE0201]).replace("\0", "0");
        String sIPbinstr_21BCE0201 = ip2bin_21BCE0201(ipDecArr, resbitnet_21BCE0201) + H0S_21BCE0201;
        int[] sIPbinarray_21BCE0201 = bin2deciarr_21BCE0201(sIPbinstr_21BCE0201);
        String startIPDecStr = decimalArrayToString(sIPbinarray_21BCE0201);
        String H1S_21BCE0201 = new String(new char[resbithost_21BCE0201]).replace("\0", "1");
        String endIPBinStr = ip2bin_21BCE0201(ipDecArr, resbitnet_21BCE0201) + H1S_21BCE0201;
        int[] endIPBinArr = bin2deciarr_21BCE0201(endIPBinStr);
        String endIPDecStr = decimalArrayToString(endIPBinArr);
        String limb_21BCE0201 = "255.255.255.255";
        String dirb_21BCE0201 = endIPDecStr;
        System.out.println("Reserved bits for Network: " + resbitnet_21BCE0201);
        System.out.println("Reserved bits for Host: " + resbithost_21BCE0201);
        System.out.println("Total number of hosts in that network: " + thost_21BCE0201);
        System.out.println("Starting IP: " + startIPDecStr);
        System.out.println("Ending IP: " + endIPDecStr);
        System.out.println("Lmited braodcast address: " + limb_21BCE0201);
        System.out.println("Directed broadcast address: " + dirb_21BCE0201);
    }
    private static String ip2bin_21BCE0201(String[] ipDecArr, int resbitnet_21BCE0201) {
        StringBuilder ipBinStr = new StringBuilder();
        for (int i = 0; i < 4; i++) {
            ipBinStr.append(String.format("%8s", Integer.toBinaryString(Integer.parseInt(ipDecArr[i]))).replace(' ', '0'));
        }
        return ipBinStr.substring(0, resbitnet_21BCE0201);
    }
    private static int[] bin2deciarr_21BCE0201(String binaryStr) {
        int[] decimalArr = new int[4];
        for (int i = 0; i < 32; i += 8) {
            decimalArr[i / 8] = Integer.parseInt(binaryStr.substring(i, i + 8), 2);
        }
        return decimalArr;
    }
    private static String decimalArrayToString(int[] decimalArr) {
        StringBuilder decimalStr = new StringBuilder();
        for (int i = 0; i < 3; i++) {
            decimalStr.append(decimalArr[i]).append(".");
        }
        decimalStr.append(decimalArr[3]);
        return decimalStr.toString();
    }
}