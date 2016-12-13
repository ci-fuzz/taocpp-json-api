// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef TAO_CPP_PEGTL_INTERNAL_EOF_HH
#define TAO_CPP_PEGTL_INTERNAL_EOF_HH

#include "skip_control.hh"

#include "../analysis/generic.hh"

namespace tao_json_pegtl
{
   namespace internal
   {
      struct eof
      {
         using analyze_t = analysis::generic< analysis::rule_type::OPT >;

         template< typename Input >
         static bool match( Input & in )
         {
            return in.empty();
         }
      };

      template<>
      struct skip_control< eof > : std::true_type {};

   } // namespace internal

} // namespace tao_json_pegtl

#endif
