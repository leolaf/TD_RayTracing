cmake_minimum_required(VERSION 3.5)
project( DisplayImage )
set (CMAKE_CXX_STANDARD 11)

SET( MAIN_EXEC
     main 
     # vous pouvez ajouter d'autres programmes ici
     )

FOREACH(FILE ${MAIN_EXEC})
            add_executable( ${FILE} ${FILE}.cpp )
ENDFOREACH()