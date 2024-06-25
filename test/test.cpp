#include "gtest/gtest.h"
#include "characterEntityTest.h"
#include "characterTest.h"
#include "playerTest.h"
#include "shockTest.h"
#include "stoneTest.h"
#include "agilityTest.h"
#include "vultureTest.h"
#include "ogerTest.h"
#include "teleTest.h"
#include "sparkTest.h"
#include "anodizedTest.h"
#include "weedTest.h"
#include "tidalTest.h"
#include "fastLevelTest.h"
#include "mediumLevelTest.h"
#include "slowLevelTest.h"
#include "randomLevelTest.h"
#include "bigBattleTest.h"
#include "pokehubTest.h"
#include "atkTests.h"
#include "CommonSphereTest.hpp"
#include "RareSphereTest.hpp"
#include "MasterSphereTest.hpp"
#include "SmallPotionTest.hpp"
#include "MediumPotionTest.hpp"
#include "LargePotionTest.hpp"
#include "battleTest.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
