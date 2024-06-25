CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(GameTest
    test/test.cpp
    source/characterEntity.cpp
    source/character.cpp
    source/player.cpp
    source/shock.cpp
    source/stone.cpp
    source/agility.cpp
    source/vulture.cpp
    source/oger.cpp
    source/tele.cpp
    source/spark.cpp
    source/anodized.cpp
    source/weed.cpp
    source/tidal.cpp
    source/levelStrategy.cpp
    source/fastLevel.cpp
    source/mediumLevel.cpp
    source/slowLevel.cpp
    source/randomLevel.cpp
    source/bigBattle.cpp
    source/pokehub.cpp
    source/battle.cpp
)

ADD_EXECUTABLE(pokeman
    main.cpp
    source/characterEntity.cpp
    source/character.cpp
    source/player.cpp
    source/shock.cpp
    source/stone.cpp
    source/agility.cpp
    source/vulture.cpp
    source/oger.cpp
    source/tele.cpp
    source/spark.cpp
    source/anodized.cpp
    source/weed.cpp
    source/tidal.cpp
    source/levelStrategy.cpp
    source/fastLevel.cpp
    source/mediumLevel.cpp
    source/slowLevel.cpp
    source/randomLevel.cpp
    source/bigBattle.cpp
    source/pokehub.cpp
    source/battle.cpp
)

TARGET_LINK_LIBRARIES(GameTest gtest)
TARGET_COMPILE_DEFINITIONS(GameTest PRIVATE gtest_disable_pthreads=ON)
