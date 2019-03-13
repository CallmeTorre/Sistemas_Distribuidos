import java.util.*; 
import java.nio.charset.*; 
  
class random { 
  
    static String getAlphaNumericString(int n) 
    { 
  
        byte[] array = new byte[256]; 
        new Random().nextBytes(array); 
  
        String randomString 
            = new String(array, Charset.forName("UTF-8")); 
  
         
        StringBuffer r = new StringBuffer(); 
  
        // Append first 20 alphanumeric characters 
        // from the generated random String into the result 
        for (int k = 0; k < randomString.length(); k++) { 
  
            char ch = randomString.charAt(k); 
  
            if ( (ch >= 'A' && ch <= 'Z') && (n > 0)) { 
  
                r.append(ch); 
                n--; 
            } 
        } 
     int intIndex = r.indexOf("IPN");
      
      if(intIndex == - 1) {
         System.out.println(".");
      } else {
         System.out.println("IPN " + intIndex);
      }

        // return the resultant string 
        return r.toString(); 


    } 
  
    public static void main(String[] args) 
    { 
        // size of random alphanumeric string 
        int n = 3; 
  
        for (int i=0;i<=100000000;i++ ) {
            getAlphaNumericString(n); 
        }
        
     

    } 
} 
