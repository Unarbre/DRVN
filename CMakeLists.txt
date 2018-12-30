#Project declaration
project(DRVN)

#Add exec
add_executable(
    DRVNEXE
    source/main.c
    source/land.c
    source/landInitialisation.c
    source/memoryRelease.c
    source/MU.c
    source/populationInit.c
    source/Uassets.c

    proto/land.h
    proto/landInitialisation.h
    proto/memoryRelease.h
    proto/MU.h
    proto/populationInit.h
    proto/supervisor.h



)