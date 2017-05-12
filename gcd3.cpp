int gcd( int x, int y )
{
   if( x < y )
      return gcd( y, x );

   int f = x % y;
   if( f == 0 )
     return y;
   else
      return gcd( y, f );
}
