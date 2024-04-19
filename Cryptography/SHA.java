import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;

public class SHA {
    public static void main(String[] args) {
        String message = "Manvendra Singh";
        String secretKey = "secret";
        System.out.println("Given Text: "+message);
        try {
            String hmacSHA256 = generateHmacSHA256(message, secretKey);
            System.out.println("SHA: " + hmacSHA256);
        } catch (NoSuchAlgorithmException | InvalidKeyException e) {
            System.err.println("Error generating SHA: " + e.getMessage());
        }
    }
    public static String generateHmacSHA256(String message, String secretKey)
            throws NoSuchAlgorithmException, InvalidKeyException {
        Mac mac = Mac.getInstance("HmacSHA256");
        SecretKeySpec secretKeySpec = new SecretKeySpec(secretKey.getBytes(), "HmacSHA256");
        mac.init(secretKeySpec);
        byte[] hmacBytes = mac.doFinal(message.getBytes());
        StringBuilder hexString = new StringBuilder();
        for (byte b : hmacBytes) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString();
    }
}