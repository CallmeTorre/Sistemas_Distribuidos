import java.lang.*;
public class cpu {

   /* This is my first java program.
    * This will print 'Hello World' as the output
    */

   public static void main(String []args) {
        double MAX = 100000000;
        double i = 0;
        double seno = 0;
        double coseno = 0;
        double tangente = 0;
        double logaritmo = 0;
        double raizCuadrada = 0;
        while(i < MAX){
            seno += Math.sin(i);
            coseno += Math.cos(i);
            tangente += Math.tan(i);
            logaritmo += Math.log(i);
            raizCuadrada += Math.sqrt(i);
            i++;
        }
   }
}