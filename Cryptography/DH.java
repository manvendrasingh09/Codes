import java.math.BigInteger;
import java.security.SecureRandom;

class DH {
    private BigInteger privateKey;
    private BigInteger publicKey;
    private BigInteger sharedKey;
    private BigInteger p; 
    private BigInteger g;  
    public DH(BigInteger p, BigInteger g) {
        this.p = p;
        this.g = g;
        this.privateKey = new BigInteger(1024, new SecureRandom());
        this.publicKey = g.modPow(privateKey, p);
    }
    public void generateSharedKey(BigInteger otherPublicKey) {
        this.sharedKey = otherPublicKey.modPow(privateKey, p);
    }
    public BigInteger getPublicKey() {
        return publicKey;
    }
    public BigInteger getSharedKey() {
        return sharedKey;
    }
    public static void main(String[] args) {
        BigInteger p = new BigInteger("FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD1" +
                                    "29024E088A67CC74020BBEA63B139B22514A08798E3404DD" +
                                    "EF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245" +
                                    "E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7ED" +
                                    "EE386BFB5A899FA5AE9F24117C4B1FE649286651ECE65381" +
                                    "FFFFFFFFFFFFFFFF", 16);
        BigInteger g = new BigInteger("2");
        DH alice = new DH(p, g);
        DH bob = new DH(p, g);
        alice.generateSharedKey(bob.getPublicKey());
        bob.generateSharedKey(alice.getPublicKey());
        System.out.println("Alice's Shared Key: " + alice.getSharedKey().toString(16));
        System.out.println();
        System.out.println("Bob's Shared Key:   " + bob.getSharedKey().toString(16));
        System.out.println();
        System.out.println("Shared keys are equal: " + alice.getSharedKey().equals(bob.getSharedKey()));
    }
}
