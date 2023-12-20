import java.util.*;
class FillAndSort {
   public static void main( String[ ] args ) {
      int n = Integer.parseInt( args[ 0 ] ); 
      double[ ] nums = new double[ n ];
      Random r = new Random();int i = 0;
      while ( i < n ) {                      
         nums[ i ] = r.nextDouble();
         i = i + 1;
      }
      print( nums ); 
      Arrays.sort( nums );
      print( nums );     
   }
   static void print( double[ ] a ) {
      System.out.println();
      for ( int i = 0; i < a.length; i++ )
         System.out.println( a[ i ] );
   }   
}

