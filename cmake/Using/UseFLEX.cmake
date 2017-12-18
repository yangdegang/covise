MACRO(USE_FLEX)
 set(SAVED_FLEX_CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})
 if(APPLE)
    if(NOT FLEX_INCLUDE_DIR)
       EXECUTE_PROCESS(COMMAND xcrun -find cc
          OUTPUT_VARIABLE XCRUN_CC
          ERROR_VARIABLE XCRUN_CC_ERROR
          RESULT_VARIABLE XCRUN_CC_RESULT
          OUTPUT_STRIP_TRAILING_WHITESPACE)
       #message("XCRUN_CC: ${XCRUN_CC}")
       string(REGEX REPLACE "^(.*)/bin/cc" "\\1" TOOLCHAIN_DIR "${XCRUN_CC}")
       #message("TOOLCHAIN_DIR: ${TOOLCHAIN_DIR}")
       set(CMAKE_PREFIX_PATH ${TOOLCHAIN_DIR} ${CMAKE_PREFIX_PATH})
       #message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
    endif()
  endif()
  covise_find_package(FLEX)
  set(CMAKE_PREFIX_PATH ${SAVED_FLEX_CMAKE_PREFIX_PATH})
  IF ((NOT FLEX_FOUND) AND (${ARGC} LESS 1))
    USING_MESSAGE("Skipping because of missing FLEX")
    RETURN()
 ENDIF((NOT FLEX_FOUND) AND (${ARGC} LESS 1))
 if(NOT FLEX_INCLUDE_DIR)
    find_path(FLEX_INCLUDE_DIR "FlexLexer.h")
    if((NOT FLEX_INCLUDE_DIR) AND (${ARGC} LESS 1))
      USING_MESSAGE("Skipping because of missing FlexLexer.h")
      #return()
    endif()
 endif()
 IF(NOT FLEX_USED AND FLEX_FOUND)
    SET(FLEX_USED TRUE)
    if (FLEX_INCLUDE_DIR)
       INCLUDE_DIRECTORIES(${FLEX_INCLUDE_DIRS})
    endif()
    if(NOT APPLE AND NOT UNIX)
       SET(EXTRA_LIBS ${EXTRA_LIBS} ${FLEX_LIBRARIES})
    endif()
  ENDIF()
ENDMACRO(USE_FLEX)

