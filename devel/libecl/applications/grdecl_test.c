/*
   Copyright (C) 2012  Statoil ASA, Norway. 
    
   The file 'grdecl_test.c' is part of ERT - Ensemble based Reservoir Tool. 
    
   ERT is free software: you can redistribute it and/or modify 
   it under the terms of the GNU General Public License as published by 
   the Free Software Foundation, either version 3 of the License, or 
   (at your option) any later version. 
    
   ERT is distributed in the hope that it will be useful, but WITHOUT ANY 
   WARRANTY; without even the implied warranty of MERCHANTABILITY or 
   FITNESS FOR A PARTICULAR PURPOSE.   
    
   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
   for more details. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <ecl_kw.h>
#include <util.h>

int main(int argc , char ** argv) {
  FILE * stream = util_fopen( argv[1] , "r");

  {
    while (true) {
      ecl_kw_type * grdecl_kw = ecl_kw_fscanf_alloc_current_grdecl( stream , ECL_FLOAT_TYPE );
      if (grdecl_kw != NULL) {
        printf("Loaded %s - %d elements \n", ecl_kw_get_header( grdecl_kw ) , ecl_kw_get_size( grdecl_kw ));
        ecl_kw_free( grdecl_kw );
      } else
        break;
    }
  }
  
  fclose( stream );
}