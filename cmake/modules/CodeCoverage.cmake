# USAGE:
# in root CMakeLists.txt turn option CodeCoverage on
# cmake
# make
# make "executable_name"_coverage

# Check prereqs
FIND_PROGRAM(GCOV_PATH gcov)
FIND_PROGRAM(LCOV_PATH lcov)
FIND_PROGRAM(GENHTML_PATH genhtml)

IF (NOT GCOV_PATH)
    MESSAGE(FATAL_ERROR "gcov not found! Aborting...")
ENDIF () # NOT GCOV_PATH

IF (NOT LCOV_PATH)
    MESSAGE(FATAL_ERROR "lcov not found! Aborting...")
ENDIF () # NOT LCOV_PATH

IF (NOT GENHTML_PATH)
    MESSAGE(FATAL_ERROR "genhtml not found! Aborting...")
ENDIF () # NOT GENHTML_PATH

FUNCTION(SETUP_TARGET_FOR_COVERAGE _targetname _testrunner _outputname)

    # Setup target
    ADD_CUSTOM_TARGET(${_targetname}

            # Cleanup lcov
            ${LCOV_PATH} --directory . --zerocounters

            # Run tests
            COMMAND ${_testrunner}

            # Capturing lcov counters and generating report
            COMMAND ${LCOV_PATH} --directory . --capture --output-file ${_outputname}.info
            COMMAND ${LCOV_PATH} --remove ${_outputname}.info 'build/*' 'tests/*' '/usr/*' --output-file ${_outputname}.info.cleaned
            COMMAND ${GENHTML_PATH} -o ${_outputname} ${_outputname}.info.cleaned
            COMMAND ${CMAKE_COMMAND} -E remove ${_outputname}.info ${_outputname}.info.cleaned
            )

    # Show info where to find the report
    ADD_CUSTOM_COMMAND(TARGET ${_targetname} POST_BUILD
            COMMAND ;
            COMMENT "Open ./${_outputname}/index.html in your browser to view the coverage report."
            )

ENDFUNCTION() # SETUP_TARGET_FOR_COVERAGE
