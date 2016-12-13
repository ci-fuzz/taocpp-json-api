// Copyright (c) 2016 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef TAO_CPP_PEGTL_CRLF_EOL_HH
#define TAO_CPP_PEGTL_CRLF_EOL_HH

namespace tao_json_pegtl
{
   struct crlf_eol
   {
      static constexpr int ch = '\n';

      template< typename Input >
      static eol_pair match( Input & in )
      {
         eol_pair p = { false, in.size( 2 ) };
         if ( p.second > 1 ) {
            if ( ( in.peek_char() == '\r' ) && ( in.peek_char( 1 ) == '\n' ) ) {
               in.bump_to_next_line( 2 );
               p.first = true;
            }
         }
         return p;
      }
   };

} // namespace tao_json_pegtl

#endif
