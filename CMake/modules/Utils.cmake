
macro(CodeSign file)
  add_custom_command(
      TARGET ${APP_EXE_NAME}
      POST_BUILD COMMAND ${CMAKE_COMMAND} -E echo "Attempting to Code Sign: ${file}"
      POST_BUILD COMMAND /bin/sh -c
      \"COMMAND_DONE=0 \;

      if codesign --force --verbose ${file} --sign ${CODE_SIGN_IDENTITY} \; then
        COMMAND_DONE=1 \;
        echo \;
      fi \;

      if [ \\$$COMMAND_DONE -eq 0 ] \; then
          echo Framework codesign failed for ${APP_EXE_PATH} \;
          exit 1 \;
      fi\"
  )
endmacro()
