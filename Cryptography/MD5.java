import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

public class MD5 {
    public static void main(String[] args) {
        try {
            String message = "Manvendra Singh";
            String secretKey = "mySecretKey";
            String hmac = generateHmacSHA256(message, secretKey);
            System.out.println("Given Text: " + message);
            System.out.println("MD5: " + hmac);
        } catch (Exception e) {
            System.err.println("Error generating MD5: " + e.getMessage());
        }
    }
    public static String generateHmacSHA256(String data, String key) throws Exception {
        SecretKeySpec secretKeySpec = new SecretKeySpec(key.getBytes(), "HmacSHA256");
        Mac mac = Mac.getInstance("HmacSHA256");
        mac.init(secretKeySpec);
        byte[] hmacBytes = mac.doFinal(data.getBytes());
        return Base64.getEncoder().encodeToString(hmacBytes);
    }
}